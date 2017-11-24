#ifndef MACROS_H
#define MACROS_H

#define MSG_CANT_LOAD(filepath,errorString)\
        QMessageBox::information(\
                this,\
                QGuiApplication::applicationDisplayName(),\
                tr("Cannot load %1: %2").arg(\
                    QDir::toNativeSeparators(filepath),\
                    errorString)\
                 );\

#endif // MACROS_H
