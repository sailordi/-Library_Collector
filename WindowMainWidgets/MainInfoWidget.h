#ifndef MAININFOWIDGET_H
#define MAININFOWIDGET_H

#include "Base/LayoutWidget/SingleLayoutWidget.h"

class QLineEdit;
class QTextEdit;
class QPushButton;

/*! \class MainInfoWidget
 * \brief The class contains widgets for the main info layout
 *
 * Incudes: SingleLayoutWidget
 *
 * Forward declarations: QLineEdit, QTextEdit & QPushButton
 *
 * Inherits: SingleLayoutWidget
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2020-06-10
 * \date Last update: 2020-06-10
*/
class MainInfoWidget : public SingleLayoutWidget
{
    Q_OBJECT
public:
    /*! Constructor
     * \param l - The layout for the main info widgets
     * \param parent - The parent [Default: nullptr]
    */
    MainInfoWidget(QGridLayout* l,QWidget* parent = nullptr);

    /*! Sets the output path
     * \param outputPath - The output path
    */
    void setOutputPath(QString outputPath);
    /*! Sets the header path
     * \param headerPath - The header path
    */
    void setHeaderPath(QString headerPath);

    /*! Returns the output path
     * \returns QString
    */
    QString outputPath();
    /*! Returns the header path
     * \returns QString
    */
    QString headerPath();

private:
    QTextEdit* v_outputPathE = nullptr,*v_headerPathE = nullptr;
    QLineEdit* v_libraryBaseNameE = nullptr;
    QPushButton* v_outputPathB = nullptr,*v_headerPathB = nullptr;

    /*! Initializes widgets that are used */
    void init();

};
#endif // MAININFOWIDGET_H
