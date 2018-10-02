import QtQuick 2.0

Item {
    id: root

    Rectangle {
        anchors.fill: parent
        color: "cyan"
    }

    TestListModel {
        id: myListModel
    }

    ListView {
        id: listView

        anchors.fill: parent
        model: myListModel.exportListModel
        delegate: myListModel.exportDelegate

        highlight: Rectangle {
            width: parent.width
            color: "lightgray"
        }
    }
}
