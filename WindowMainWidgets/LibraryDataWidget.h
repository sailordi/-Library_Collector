#ifndef LIBRARYDATAWIDGET_H
#define LIBRARYDATAWIDGET_H

#include "Base/LayoutWidget/SingleLayoutWidget.h"

class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;

/*! \class LibraryDataWidget
 * \brief The class is the main ui for the ptogram
 *
 * Incudes: SingleLayoutWidget
 *
 * Forward declarations: QLabel,QLineEdit,QTextEdit & QPushButton
 *
 * Inherits: SingleLayoutWidget
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2020-06-07
 * \date Last update: 2020-06-07
*/
class LibraryDataWidget : public SingleLayoutWidget
{
    Q_OBJECT
public:
    /*! Constructor
     * @param l - The layout
     * @param dataStr - The data label string
     * @param fileD - File dialog string
     * @param name - If name field is needed
     * @param parent - The parent to be used [Default: nullptr]
    */
    LibraryDataWidget(QGridLayout* l,QString dataStr,bool name,QWidget *parent = nullptr);

    /*! Sets the path data
     * @param str - Path string
    */
    void setPath(QString str);

private:
    QLabel* v_dataL = nullptr,*v_pathL = nullptr,*v_nameL = nullptr;
    QTextEdit* v_pathE = nullptr;
    QLineEdit* v_nameE = nullptr;
    QPushButton* v_selBtn = nullptr;

    bool v_name;

    void init(QString dataStr);

};
#endif // LIBRARYDATAWIDGET_H
