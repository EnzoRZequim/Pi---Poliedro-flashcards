

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls
import FlashCard
import QtQuick3D 6.8

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height
    color: "#ffffff"

    Button {
        id: btSair
        x: 715
        y: 798
        width: 490
        height: 100
        text: qsTr("Sair")
        font.bold: true
        font.pointSize: 64
        font.family: "Arial"
    }

    Button {
        id: btCriaEdita
        x: 715
        y: 526
        width: 490
        height: 100
        text: qsTr("Criar/editar")
        font.pointSize: 64
        font.family: "Arial"
        font.bold: true
    }

    Button {
        id: btHistorico
        x: 715
        y: 662
        width: 490
        height: 100
        text: qsTr("Histórico\n")
        font.pointSize: 64
        font.family: "Arial"
        font.bold: true
    }

    Button {
        id: btJogar
        x: 715
        y: 390
        width: 490
        height: 100
        text: qsTr("Jogar")
        font.pointSize: 64
        font.family: "Arial"
        font.bold: true
    }

    Item {
        id: __materialLibrary__
    }

    Image {
        id: image
        x: 460
        y: 0
        width: 1000
        height: 384
        source: "images/Logo_Poliedro_Horiz_EDUCACAO.webp"
        fillMode: Image.PreserveAspectFit
    }
    states: [
        State {
            name: "clicked"
        }
    ]
}
