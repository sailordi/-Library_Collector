#ifndef EXCLUDEPATHSVIEWWIDGET_H
#define EXCLUDEPATHSVIEWWIDGET_H

#include "Base/LayoutWidget/SingleLayoutWidget.h"

#include <QList>
#include <QString>

class QLabel;

class TreeViewAdapterNoChildRows;

/*! \class BuildDataViewWidget
 * \brief The class contains widgets for the build data view
 *
 * Incudes: QList, QString & SingleLayoutWidget
 *
 * Forward declarations: QLabel & TreeViewAdapterNoChildRows
 *
 * Inherits: SingleLayoutWidget
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2020-06-22
 * \date Last update: 2020-06-22
*/
class ExcludePathsViewWidget : public SingleLayoutWidget
{
public:
    /*! Constructor
     * \param l - The layout for the build data view widgets
     * \param parent - The parent [Default: nullptr]
    */
    ExcludePathsViewWidget(QVBoxLayout* l,QWidget *parent = nullptr);
    /*! Deconstructor */
    ~ExcludePathsViewWidget();

private:
    QLabel* v_excludedPathsL = nullptr;

    QList<QString> v_excludedPathList;

    TreeViewAdapterNoChildRows* v_view = nullptr;

};
#endif // EXCLUDEPATHSVIEWWIDGET_H
