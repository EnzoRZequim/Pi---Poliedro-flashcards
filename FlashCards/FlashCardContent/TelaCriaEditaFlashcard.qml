

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

    function salvar(){
        ponte.insertFlashcard(perguntaFlashCard.text,respostaFlashCard.text,1,1)
    }

    Item {
        id: __materialLibrary__
    }

    Rectangle {
        id: rectangle1D9D9D14
        x: 139
        y: 164
        width: 1610
        height: 100
        color: "#d9d9d9"
        Text {
            id: text1
            x: 8
            y: 8
            width: 461
            height: 84
            text: "Pergunta Flash Card:"
            font.pixelSize: 64
            font.family: "Arial"
            font.bold: true
        }

        TextEdit {
            id: perguntaFlashCard
            x: 677
            y: 8
            width: 925
            height: 84
            text: qsTr("Digite aqui")
            font.pixelSize: 54
        }
    }

    Rectangle {
        id: rectangle1D9D9D15
        x: 139
        y: 282
        width: 1610
        height: 100
        color: "#d9d9d9"
        Text {
            id: text2
            x: 8
            y: 8
            width: 461
            height: 84
            text: "Resposta Flash Card:"
            font.pixelSize: 64
            font.family: "Arial"
            font.bold: true
        }

        TextEdit {
            id: respostaFlashCard
            x: 677
            y: 8
            width: 925
            height: 84
            text: qsTr("Digite aqui")
            font.pixelSize: 54
        }
    }

    Button {
        id: btSalvar
        x: 292
        y: 788
        width: 521
        height: 100
        text: qsTr("Salvar")
        font.pointSize: 64
        font.family: "Arial"
        font.bold: true
        onClicked: salvar()
    }

    Button {
        id: btDescartar
        x: 1047
        y: 788
        width: 521
        height: 100
        text: qsTr("Descartar")
        font.pointSize: 64
        font.family: "Arial"
        font.bold: true
        onClicked: navigateTo("TelaCriaEditaGeral")
    }

    Button {
        id: btHome
        x: 26
        y: 22
        width: 133
        height: 114
        text: qsTr("")

        onClicked: navigateTo("TelaInicio")
    }

    Image {
        id: home2
        x: 34
        y: 22
        source: "../images/home 2.png"
        fillMode: Image.PreserveAspectFit
    }

    ComboBox {
        id: comboBox
        x: 1312
        y: 411
        width: 437
        height: 100
        z: 1
        font.bold: true
        font.family: "Arial"
        font.pointSize: 42
        displayText: "Dificuldade"
        model: ["Fácil", "Médio", "Difícil"]
    }

    ComboBox {
        id: comboBox2
        x: 139
        y: 411
        width: 490
        height: 100
        displayText: "Materia"
        font.bold: true
        font.family: "Arial"
        font.pointSize: 52
        model: ["Matemática", "História", "Geografia"]
    }
    states: [
        State {
            name: "clicked"
        }
    ]
}
