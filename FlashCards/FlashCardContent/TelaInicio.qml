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
        id: btJogar
        x: 715
        y: 390
        width: 490
        height: 100
        text: qsTr("Jogar")
        font.pointSize: 64
        font.family: "Arial"
        font.bold: true

        onClicked: navigateTo("TelaJogando")  // Navega para TelaJogando.qml
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

        onClicked: navigateTo("TelaCriaEditaGeral")  // Navega para TelaCriaEditaGeral.qml
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

        onClicked: navigateTo("TelaHistoricoGeral")  // Navega para TelaHistoricoGeral.qml
    }

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

        onClicked: navigateTo("TelaPopUpSair")  // Navega para TelaPopUpSair.qml
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

    Item {
        id: __materialLibrary__
    }
}
