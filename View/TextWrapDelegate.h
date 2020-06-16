#ifndef TEXTWRAPDELEGATE_H
#define TEXTWRAPDELEGATE_H

#include <QStyledItemDelegate>

/*! \class TextWrapDelegate
 * \brief The class is a delegate that allows text wrapping in a view
 *
 * Incudes: QStyledItemDelegate
 *
 * Inherits: QStyledItemDelegate
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2020-06-10
 * \date Last update: 2020-06-16
*/
class TextWrapDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    /*! Constructor
     * \param extraWidth - How much extra width the item should have
     * \param extraHeight - How much extra height the item should have
     * \param parent - The parent [Default: nullptr]
    */
    TextWrapDelegate(int extraWidth,int extraHeight,Qt::ItemDataRole role,QWidget *parent = nullptr);

private:
    int v_extraWidth = 0,v_extraHeight = 0;
    Qt::ItemDataRole v_role = Qt::DisplayRole;

};
#endif // TEXTWRAPDELEGATE_H
