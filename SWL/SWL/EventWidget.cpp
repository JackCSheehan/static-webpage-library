#include "EventWidget.h"

/*
Default constructor
*/
EventWidget::EventWidget()
{
   onError = "";
   onHashChange = "";
   onLoad = "";
   onPageShow = "";
   onResize = "";
   onUnload = "";

   onBlur = "";
   onChange = "";
   onContextMenu = "";
   onFocus = "";
   onInvalid = "";
   onSubmit = "";

   onKeyDown = "";
   onKeyPress = "";
   onKeyUp = "";

   onClick = "";
   onDoubleClick = "";
   onMouseDown = "";
   onMouseMove = "";
   onMouseUp = "";
   onMouseOut = "";
   onMouseOver = "";

   onScroll = "";

   onCopy = "";
   onPaste = "";
}

/*
Writes the event attributes.
*/
void EventWidget::write(std::ofstream& file) const
{
   //Write base class attributes
   Widget::write(file);

   if (!onError.empty()) file << "onerror=\"" << onError << "\" ";
   if (!onHashChange.empty()) file << "onhashchange=\"" << onHashChange << "\" ";
   if (!onLoad.empty()) file << "onload=\"" << onLoad << "\" ";
   if (!onPageShow.empty()) file << "onpageshow=\"" << onPageShow << "\" ";
   if (!onResize.empty()) file << "onresize=\"" << onResize << "\" ";
   if (!onUnload.empty()) file << "onunload=\"" << onUnload << "\" ";
   if (!onBlur.empty()) file << "onblur=\"" << onBlur << "\" ";
   if (!onChange.empty()) file << "onchange=\"" << onChange << "\" ";
   if (!onContextMenu.empty()) file << "oncontextmenu=\"" << onContextMenu << "\" ";
   if (!onFocus.empty()) file << "onfocus=\"" << onFocus << "\" ";
   if (!onInvalid.empty()) file << "oninvalid=\"" << onInvalid << "\" ";
   if (!onSubmit.empty()) file << "onsubmit=\"" << onSubmit << "\" ";
   
   if (!onKeyDown.empty()) file << "onkeydown=\"" << onKeyDown << "\" ";
   if (!onKeyPress.empty()) file << "onkeypress=\"" << onKeyPress << "\" ";
   if (!onKeyUp.empty()) file << "onkeyup=\"" << onKeyUp << "\" ";
   
   if (!onClick.empty()) file << "onclick=\"" << onClick << "\" ";
   if (!onDoubleClick.empty()) file << "ondoublecheck=\"" << onDoubleClick << "\" ";
   if (!onMouseDown.empty()) file << "onmouseclick=\"" << onMouseDown << "\" ";
   if (!onMouseMove.empty()) file << "onmousemove=\"" << onMouseMove << "\" ";
   if (!onMouseUp.empty()) file << "onmouseup=\"" << onMouseUp << "\" ";
   if (!onMouseOut.empty()) file << "onmouseout=\"" << onMouseOut << "\" ";
   if (!onMouseOver.empty()) file << "onmouseover=\"" << onMouseOver << "\" ";

   if (!onScroll.empty()) file << "onscroll=\"" << onScroll << "\" ";

   if (!onCopy.empty()) file << "oncopy=\"" << onCopy << "\" ";
   if (!onPaste.empty()) file << "onpaste=\"" << onPaste << "\" ";
}