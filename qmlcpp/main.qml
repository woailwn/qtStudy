import QtQuick 2.15
import Cpp.MyPainter
import QtQuick.Controls
import QtQuick.Dialogs
Window {
    width:800
    height:600
    visible:true
    MyPainter{
        anchors.fill:parent
        id:mypainter
        MouseArea{
            Row{
                spacing:10
                Slider{
                    from: 1
                    to:100
                    value:mypainter.penSize
                    onValueChanged: mypainter.penSize=value
                    anchors.verticalCenter: rect1.verticalCenter
                }
                ColorDialog{
                    id:colorDialog
                    selectedColor: "lightblue"
                    onAccepted: mypainter.penColor=colorDialog.selectedColor;
                }

                Rectangle{
                    id:rect1
                    width:30
                    height:30
                    color:colorDialog.selectedColor
                    MouseArea{
                        anchors.fill: parent
                        onClicked:{
                            colorDialog.open()

                        }
                    }
                }
            }

            anchors.fill: parent
            hoverEnabled: true
            //鼠标按下
            onPressed: (mouse)=>
            {
                parent.beginPaint(Qt.point(mouse.x,mouse.y))
            }

            onPositionChanged: (mouse)=>
            {
                if(!mouse.buttons & Qt.LeftButton) return;
                parent.movePaint(Qt.point(mouse.x,mouse.y))
            }
        }
    }
}
