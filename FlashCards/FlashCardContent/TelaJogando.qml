

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls

Item {
    id: root
    width: 1920
    height: 1080

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 1920
        height: 1088
        color: "#ffffff"

        Button {
            id: btHome
            x: 29
            y: 42
            width: 133
            height: 114
            text: qsTr("")
        }
    }

    Image {
        id: home2
        x: 37
        y: 43
        source: "../images/home 2.png"
        fillMode: Image.PreserveAspectFit
    }
}
