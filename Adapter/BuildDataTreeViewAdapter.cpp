#include "BuildDataTreeViewAdapter.h"

#include <QTreeView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QStringList>

#include "Adapter/PathItemCreator.h"
#include "View/TextWrapDelegate.h"

//Public functions
BuildDataTreeViewAdapter::BuildDataTreeViewAdapter() : TreeViewAdapterNoChildRows(new QTreeView(),true) {
    this->setHeaders({Qt::AlignCenter,Qt::AlignCenter,Qt::AlignCenter},
                        {"Build name","Debug path","Release path"});

    this->v_view->header()->setSectionResizeMode(QHeaderView::Interactive);

    this->v_view->setItemDelegateForColumn(1,new TextWrapDelegate(420,80,Qt::UserRole+1) );
    this->v_view->setItemDelegateForColumn(2,new TextWrapDelegate(420,80,Qt::UserRole+1) );

    QString str = "QTreeView{outline:0;}";
    str.append("QTreeView::item:selected{background-color: #D5E9F8;color: black;}");
    str.append("QTreeView::item{padding:2px;font: 16pt Times New Roman;border: 1px solid rgb(0,0,0);}");
    str.append("QTreeView::item:has-children{border: 1px solid rgb(0,0,0);}");

    this->v_view->setStyleSheet(str);
    this->v_view->header()->setFont(QFont("Times New Roman",16) );
    this->view()->setFont(QFont("Times New Roman",16) );
}

//Private functions
void BuildDataTreeViewAdapter::generateColumns(QList<QStandardItem*>& l,QList<QVariant> data) {
    PathItemCreator c;

        for(int i = 0; i < data.size(); i++) {
            if(i == 0) {
                l.push_back(this->v_itemCreator->nonEditable(data.at(i),Qt::AlignCenter) );
            }
            else {
                 l.push_back(c.nonEditable(data.at(i),Qt::AlignCenter) );
            }
        }

}
