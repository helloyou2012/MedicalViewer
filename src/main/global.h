#ifndef GLOBAL_H
#define GLOBAL_H
#include <QString>

namespace Global{
    static const QString APPName="Medical Viewer";
    static const QString CHOOSETAB="Choose a Directory";
    static const QString SEARCH="Search";
    static const QString IMAGETABLE="Result List";
    static const QString IMAGEVIEW="Image View";
    static const QString SliceIcon=":/images/slice.png";
    static const QString PlaneIcon=":/images/plane.png";
    static const QString VolumeIcon=":/images/volume.png";

    static const QString GROUPSTYLESHEET="QGroupBox {\
                                       border:0px;\
                                       margin: 0px;\
                                       background-color: #476f9a;\
                                       }";
    static const QString BUTTONSTYLESHEET="QPushButton {\
                                       border: none;\
                                       background-color: transparent;\
                                       color:#FFFFFF;\
                                       min-height:32px;\
                                       max-width:100px;\
                                   }\
                                   QPushButton:pressed {\
                                       color: #00F;\
                                   }";
    static const QString LISTSTYLESHEET="QListWidget{\
                                    background-color: #29343a;\
                                    border:0px;\
                                    margin:0px;\
                                }\
                                QListWidget:item:selected:active {\
                                     background: #254567;\
                                }\
                                QListWidget:item:selected:!active {\
                                     background: #254567;\
                                }\
                                QListWidget:item:selected:disabled {\
                                     background: gray;\
                                }\
                                QListWidget:item:selected:!disabled {\
                                     background: #254567;\
                                }";
};

#endif // GLOBAL_H
