#include "TextWrapDelegate.h"

//public functions
TextWrapDelegate::TextWrapDelegate(int extraWidth,int extraHeight,Qt::ItemDataRole role,QWidget* parent) : QStyledItemDelegate(parent) {
    this->v_extraWidth = extraWidth;
    this->v_extraHeight = extraHeight;
    this->v_role = role;
}

