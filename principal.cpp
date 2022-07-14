#include "principal.h"
#include "ui_principal.h"

#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();

    ui->outCuadro->setPixmap(lienzo);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event)
{
    ui->outCuadro->setPixmap(lienzo);

}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;





    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(3);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Crear un objeto color para el relleno
    QColor colorRelleno(248, 78, 19);
    // Crear otro objeto color para el borde
    QColor colorBorde(6, 137, 215);
    // Cambiar el color del pincel
    pincel.setColor(colorBorde);
    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);
    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno);

    //obtener datos para la primero barra
    int nota1 = ui->inNota1->value();
    int altoN1 = this->getAlto(nota1);
    int incYN1 = this->incY(altoN1);
    // Dibujar primera barra
    painter.drawRect(x+50, y+50+incYN1,100,altoN1+1);






    // Crear un objeto color para el relleno
    QColor colorRelleno2(6, 137, 215);
    // Crear otro objeto color para el borde
    QColor colorBorde2(83, 81, 94);
    // Cambiar el color del pincel
    pincel.setColor(colorBorde2);
    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);
    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno2);

    //obtener datos para la segunda barra
    int nota2 = ui->inNota2->value();
    int altoN2 = this->getAlto(nota2);
    int incYN2 = this->incY(altoN2);
    // Dibujar segunda barra
    painter.drawRect(x+170, y+50+incYN2,100,altoN2+1);






    QColor cRellenoBarra2(27, 197, 0);
    QColor cBordeBarra2(255, 245, 0);
    // Estableciendo colores al pincel y al painter
    pincel.setColor(cBordeBarra2);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra2);

    //obtener datos para la segunda barra
    int nota3 = ui->inNota3->value();
    int altoN3 = this->getAlto(nota3);
    int incYN3 = this->incY(altoN3);
    // Dibujar tercera barra
    painter.drawRect(x+290,y+50+incYN3,100,altoN3+1);
    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(113, 182, 109);
    QColor cBordeBarra3(2, 10.2, 22);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);




    // Estableciendo colores al pincel y al painter
    QColor colorpro(198, 0, 120);
    pincel.setColor(colorpro);
    painter.setPen(pincel);
    painter.setBrush(colorpro);
    painter.drawRect(x+30, 450-((altoN1+altoN2+altoN3)/3),500,1);
    float pro=((nota1+nota2+nota3)/3);
    ui->promedio->setNum(pro);


    //Dibujar margen
    QColor colorinfe(228, 26, 0);
    pincel.setColor(colorinfe);
    painter.setPen(pincel);
    painter.setBrush(colorinfe);
    painter.drawRect(x, y+452,500,1);

    QColor coloriz(28, 18, 205);
    pincel.setColor(coloriz);
    painter.setPen(pincel);
    painter.setBrush(coloriz);
    painter.drawRect(x+30, y,1,500);


    //Escrobir numeros
    int px = 10;
    int py = 50;
    int nFinal = 100;
    int saltos = 5;
    int pFinal = nFinal/saltos;

    do{
        painter.drawText(px,py,QString::number(nFinal));
        py += pFinal;
        nFinal -= saltos;
    }while(nFinal>0);


}

int Principal::getAlto(int valor)
{
    return 4 * valor;
}

int Principal::incY(int alto)
{
    return 400 - alto;
}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Principal::on_pushButton_clicked(bool checked)
{

}


void Principal::on_inNota1_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota2_valueChanged(int arg2)
{
    dibujar();
}

void Principal::on_inNota3_valueChanged(int arg3)
{
    dibujar();
}

