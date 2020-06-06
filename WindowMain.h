#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WindowMain; }
QT_END_NAMESPACE

/*! \class WindowMain
 * \brief The class is the main ui for the ptogram
 *
 * Incudes: QMainWindow
 *
 * Inherits: QMainWindow
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2020-06-06
 * \date Last update: 2020-06-06
*/
class WindowMain : public QMainWindow
{
    Q_OBJECT
public:
    WindowMain(QWidget *parent = nullptr);
    ~WindowMain();

private slots:
    /*! Slot that is activated when output path selection button is clicked */
    void libraryOutPathBtnClicked();

private:
    Ui::WindowMain* v_ui = nullptr;

};
#endif // WINDOWMAIN_H
