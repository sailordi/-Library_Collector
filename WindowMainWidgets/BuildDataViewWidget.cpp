#include "BuildDataViewWidget.h"

#include <QGridLayout>

#include "Adapter/BuildDataTreeViewAdapter.h"

//Public functions
BuildDataViewWidget::BuildDataViewWidget(QGridLayout* l,QWidget* parent) : SingleLayoutWidget(parent) {
    this->clearLayout(l);

    this->v_gLayout =  l;

}

BuildDataViewWidget::~BuildDataViewWidget() {
    this->v_view->clear();
    delete this->v_view;
}
