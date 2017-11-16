#include "scrollableimage.h"
#include <QtWidgets>

ScrollableImage::ScrollableImage():
    imageLabel(new QLabel),
    scaleFactor(1)
{
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    this->setBackgroundRole(QPalette::Dark);
    this->setWidget(imageLabel);
    this->setVisible(false);
}


bool ScrollableImage::loadFile(const QString &fileName)
{
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
    }
    setImage(newImage);
    setWindowFilePath(fileName);
    //statusBar()->showMessage(tr("Opened \"%1\", %2x%3, Depth: %4").arg(QDir::toNativeSeparators(fileName)).arg(image.width()).arg(image.height()).arg(image.depth()));
    return true;
}


static QImage clipboardImage(){
    if (const QMimeData *mimeData = QGuiApplication::clipboard()->mimeData()) {
        if (mimeData->hasImage()) {
            const QImage image = qvariant_cast<QImage>(mimeData->imageData());
            if (!image.isNull())
                return image;
        }
    }
    return QImage();
}
void ScrollableImage::loadFromClipboard(){
    const QImage newImage = clipboardImage();
    if (newImage.isNull()) {
        //statusBar()->showMessage(tr("No image in clipboard"));
    } else {
        setImage(newImage);
        setWindowFilePath(QString());
        const QString message = tr("Obtained image from clipboard, %1x%2, Depth: %3")
                .arg(newImage.width()).arg(newImage.height()).arg(newImage.depth());
        //statusBar()->showMessage(message);
    }
}

void ScrollableImage::setImage(const QImage &newImage)
{
    image = newImage;
    imageLabel->setPixmap(QPixmap::fromImage(image));
    scaleFactor = 1.0;
    this->setVisible(true);
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());
}

void ScrollableImage::scaleImage(double factor)
{
    Q_ASSERT(imageLabel->pixmap() && "curent image");
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());
    adjustScrollBar(this->horizontalScrollBar(), factor);
    adjustScrollBar(this->verticalScrollBar(), factor);
}

void ScrollableImage::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

void ScrollableImage::wheelEvent(QWheelEvent *event){
    if (QApplication::keyboardModifiers() && Qt::ControlModifier){
        if (event->delta()>0){
            scaleImage(1.1);
        }else{
            scaleImage(0.9);
        }
    }
    event->accept();
}
