import QtQuick 2.6

Item {
    id: root

    property alias exportListModel: newListModel
    property alias exportDelegate: newDelegate

    ListModel {
        id: newListModel

        ListElement {
            name: "alice"
        }
        ListElement {
            name: "bill"
        }

    }

    Component {
        id: newDelegate

        Text {
            text: name
            font.pixelSize: 24
        }
    }
}
