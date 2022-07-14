#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
protected:
    void paintEvent(QPaintEvent *event)override;

private slots:
    void on_actionGuardar_triggered();

    void on_pushButton_clicked(bool checked);

    void on_inNota1_valueChanged(int arg1);

    void on_inNota2_valueChanged(int arg2);

    void on_inNota3_valueChanged(int arg3);

private:
    Ui::Principal *ui;
    QPixmap lienzo;

    void dibujar();
    int getAlto(int valor);
    int incY(int alto);
};
#endif // PRINCIPAL_H
