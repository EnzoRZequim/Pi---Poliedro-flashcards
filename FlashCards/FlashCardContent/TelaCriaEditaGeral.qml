

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

    property int maiorId

    property int segMaiorId

    property int terMaiorId

    property int quaMaiorId

    property var lista: ponte.selectAllFlashcards()

    Component.onCompleted:{
        maiorId = lista[lista.length - 1];
        segMaiorId =lista[lista.length - 2];
        terMaiorId = lista[lista.length - 3];
        quaMaiorId = lista[lista.length - 4];
    }

    // Função para navegar para outra tela
    function navigateTo(page) {
        if (stackView) {  // Verifica se o StackView está disponível
            stackView.push(page + ".qml");
        }
    }

    Button {
        id: btCriaFC
        x: 715
        y: 74
        width: 490
        height: 100
        text: qsTr("+ Novo Flash Card")
        font.pointSize: 36
        font.family: "Arial"
        font.bold: true

        onClicked: navigateTo("TelaCriaEditaFlashcard")
    }

    Item {
        id: __materialLibrary__
    }

    Rectangle {
        id: rectangle1D9D9D9
        x: 155
        y: 441
        width: 1610
        height: 100
        color: "#d9d9d9"

        Text {
            id: text1
            x: 84
            y: 14
            text: ponte.selectPergunta(maiorId)
            font.pixelSize: 64
            font.bold: true
            font.family: "Arial"
        }
    }

    Rectangle {
        id: rectangle1D9D9D10
        x: 155
        y: 565
        width: 1610
        height: 100
        color: "#d9d9d9"

        Text {
            id: text2
            x: 84
            y: 16
            width: 633
            height: 69
            text:  ponte.selectPergunta(segMaiorId)
            font.pixelSize: 64
            font.family: "Arial"
            font.bold: true
        }
    }

    Rectangle {
        id: rectangle1D9D9D11
        x: 155
        y: 689
        width: 1610
        height: 100
        color: "#d9d9d9"
    }

    Rectangle {
        id: rectangle1D9D9D12
        x: 155
        y: 816
        width: 1610
        height: 100
        color: "#d9d9d9"
    }

    Text {
        id: text4
        x: 240
        y: 705
        width: 633
        height: 69
        text:  ponte.selectPergunta(terMaiorId)
        font.pixelSize: 64
        font.family: "Arial"
        font.bold: true
    }

    Text {
        id: text5
        x: 240
        y: 832
        width: 633
        height: 69
        text: ponte.selectPergunta(quaMaiorId)
        font.pixelSize: 64
        font.family: "Arial"
        font.bold: true
    }

    Text {
        id: text6
        x: 863
        y: 457
        width: 195
        height: 69
        text: qsTr("|")
        font.pixelSize: 64
        horizontalAlignment: Text.AlignHCenter
        font.family: "Arial"
        font.bold: true
    }

    Text {
        id: text7
        x: 863
        y: 581
        width: 195
        height: 69
        text: qsTr("|")
        font.pixelSize: 64
        horizontalAlignment: Text.AlignHCenter
        font.family: "Arial"
        font.bold: true
    }

    Text {
        id: text8
        x: 863
        y: 705
        width: 195
        height: 69
        text: qsTr("|")
        font.pixelSize: 64
        horizontalAlignment: Text.AlignHCenter
        font.family: "Arial"
        font.bold: true
    }

    Text {
        id: text9
        x: 863
        y: 832
        width: 195
        height: 69
        text: qsTr("|")
        font.pixelSize: 64
        horizontalAlignment: Text.AlignHCenter
        font.family: "Arial"
        font.bold: true
    }

    Text {
        id: text10
        x: 1054
        y: 457
        width: 633
        height: 69
        text:  ponte.selectResposta(maiorId)
        font.pixelSize: 64
        font.family: "Arial"
        font.bold: true
    }

    Text {
        id: text11
        x: 1054
        y: 581
        width: 633
        height: 69
        text: ponte.selectResposta(segMaiorId)
        font.pixelSize: 64
        font.family: "Arial"
        font.bold: true
    }

    Text {
        id: text12
        x: 1054
        y: 705
        width: 633
        height: 69
        text: ponte.selectResposta(terMaiorId)
        font.pixelSize: 64
        font.family: "Arial"
        font.bold: true
    }

    Text {
        id: text13
        x: 1054
        y: 832
        width: 633
        height: 69
        text: ponte.selectResposta(quaMaiorId)
        font.pixelSize: 64
        font.family: "Arial"
        font.bold: true
    }

    Button {
        id: btHome
        x: 52
        y: 36
        width: 133
        height: 114
        text: qsTr("")

        onClicked: navigateTo("TelaInicio")
    }

    Image {
        id: home2
        x: 60
        y: 36
        source: "../images/home 2.png"
        fillMode: Image.PreserveAspectFit
    }
    states: [
        State {
            name: "clicked"
        }
    ]
}
