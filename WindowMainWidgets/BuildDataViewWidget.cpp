#include "BuildDataViewWidget.h"

#include <QLabel>
#include <QGridLayout>
#include <QTreeView>
#include <QString>
#include <QVariant>

#include "Adapter/BuildDataTreeViewAdapter.h"
#include "Data/BuildData.h"

//Public functions
BuildDataViewWidget::BuildDataViewWidget(QGridLayout* l,QWidget* parent) : SingleLayoutWidget(parent) {
    this->clearLayout(l);

    this->v_gLayout =  l;

}

BuildDataViewWidget::~BuildDataViewWidget() {
    this->v_view->clear();
    delete this->v_view;
}

QList<BuildDataP> BuildDataViewWidget::buildDataList() {
    return this->v_buildDataList;
}

QList<BuildDataP>* BuildDataViewWidget::buildDataListP() {
    return &this->v_buildDataList;
}

int BuildDataViewWidget::numberOfSelectedRows() {
    return this->v_view->numberOfSelectedRows();
}

QList<int> BuildDataViewWidget::selectedRowsPosition() {
    return this->v_view->selectedRowsPosition();
}

//Private functions
void BuildDataViewWidget::init() {
    this->v_buildInfoL = new QLabel("Build info [0]",this->v_p);
    this->v_view = new BuildDataTreeViewAdapter();

    this->v_buildInfoL->setAlignment(Qt::AlignCenter);

    int row = 0;

    this->v_gLayout->addWidget(this->v_buildInfoL,row++,0,1,1);
    this->v_gLayout->addWidget(this->v_view->view(),row++,0,1,1);
}
