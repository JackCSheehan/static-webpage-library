#ifndef EVENT_WIDGET_H
#define EVENT_WIDGET_H

#include <string>
#include <fstream>
#include "Widget.h"

/*
This class acts as a base class for all widgets that can take advantage of event attributes in HTML.
*/
class EventWidget : virtual public Widget
{
protected:
   //All the event attributes that a widget can have; correspond to HTML event attributes
   std::string onError;
   std::string onHashChange;
   std::string onLoad;
   std::string onPageShow;
   std::string onResize;
   std::string onUnload;

   std::string onBlur;
   std::string onChange;
   std::string onContextMenu;
   std::string onFocus;
   std::string onInvalid;
   std::string onSubmit;

   std::string onKeyDown;
   std::string onKeyPress;
   std::string onKeyUp;

   std::string onClick;
   std::string onDoubleClick;
   std::string onMouseDown;
   std::string onMouseMove;
   std::string onMouseUp;
   std::string onMouseOut;
   std::string onMouseOver;

   std::string onScroll;
   
   std::string onCopy;
   std::string onPaste;

   virtual void write(std::ofstream&) const override;

public:
   EventWidget();
   virtual ~EventWidget() {}

   //Getters
   std::string getOnError() const { return onError; }
   std::string getOnHashChange() const { return onHashChange; }
   std::string getOnLoad() const { return onLoad; }
   std::string getOnPageShow() const { return onPageShow; }
   std::string getOnResize() const { return onResize; }
   std::string getOnUnload() const { return onUnload; }

   std::string getOnBlur() const { return onBlur; }
   std::string getOnChange() const { return onChange; }
   std::string getOnContextMenu() const { return onContextMenu; }
   std::string getOnFocus() const { return onFocus; }
   std::string getOnInvalid() const { return onInvalid; }
   std::string getOnSubmit() const { return onSubmit; }
   
   std::string getOnKeyDown() const { return onKeyDown; }
   std::string getOnKeyPress() const { return onKeyPress; }
   std::string getOnKeyUp() const { return onKeyUp; }

   std::string getOnClick() const { return onClick; }
   std::string getOnDoubleClick() const { return onDoubleClick; }
   std::string getOnMouseDown() const { return onMouseDown; }
   std::string getOnMouseMove() const { return onMouseMove; }
   std::string getOnMouseOut() const { return onMouseOut; }
   std::string getOnMouseOver() const { return onMouseOver; }

   std::string getOnScroll() const { return onScroll; }
   
   std::string getOnCopy() const { return onCopy; }
   std::string getOnPaste() const { return onPaste; }

   //Setters
   void setOnError(std::string e) { onError = e; }
   void setOnHashChange(std::string h) { onHashChange = h; }
   void setOnLoad(std::string l) { onLoad = l; }
   void setOnPageShow(std::string s) { onPageShow = s; }
   void setOnResize(std::string r) { onResize = r; }
   void setOnUnload(std::string u) { onUnload = u; }
   
   void setOnBlur(std::string b) { onBlur = b; }
   void setOnChange(std::string c) { onChange = c; }
   void setOnContextMenu(std::string c) { onContextMenu = c; }
   void setOnFocus(std::string f) { onFocus = f; }
   void setOnInvalid(std::string i) { onInvalid = i; }
   void setOnSubmit(std::string s) { onSubmit = s; }
   
   void setOnKeyDown(std::string d) { onKeyDown = d; }
   void setOnKeyPress(std::string p) { onKeyPress = p; }
   void setOnKeyUp(std::string u) { onKeyUp = u; }

   void setOnClick(std::string c) { onClick = c; }
   void setOnDoubleClick(std::string d) { onDoubleClick = d; }
   void setOnMouseDown(std::string d) { onMouseDown = d; }
   void setOnMouseMove(std::string m) { onMouseMove = m; }
   void setOnMouseOut(std::string o) { onMouseOut = o; }
   void setOnMouseOver(std::string o) { onMouseOver = o; }

   void setOnScroll(std::string s) { onScroll = s; }
   
   void setOnCopy(std::string c) { onCopy = c; }
   void setOnPaste(std::string p) { onPaste = p; }
};

#endif