

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

    // Função para navegar para outra tela
    function navigateTo(page) {
        if (stackView) {  // Verifica se o StackView está disponível
            stackView.push(page + ".qml");
        }
    }

    Button {
        id: btSair
        x: 715
        y: 798
        width: 490
        height: 100
        text: qsTr("Sair")
        flat: false
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
        flat: false
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
        flat: false
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
        flat: false
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

    Rectangle {
        id: rectangle1
        x: 360
        y: 246
        width: 1200
        height: 600
        opacity: 0.98
        color: "#5e5e5e"

        Text {
            id: text1
            x: 307
            y: 38
            color: "#ffffff"
            text: qsTr("Deseja mesmo sair?")
            font.pixelSize: 64
            font.bold: true
        }
    }

    Button {
        id: btSim
        x: 626
        y: 463
        width: 230
        height: 100
        text: qsTr("Sim")
        font.pointSize: 64
        font.family: "Arial"
        font.bold: true
        flat: false
    }

    Button {
        id: btNao
        x: 1062
        y: 463
        width: 230
        height: 100
        text: qsTr("Não")
        font.pointSize: 64
        font.family: "Arial"
        font.bold: true
        flat: false

        onClicked: navigateTo("TelaInicio")
    }
    states: [
        State {
            name: "clicked"
        }
    ]
}
