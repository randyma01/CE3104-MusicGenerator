#include "ide.h"
#include "ui_ide.h"

#include "client.h"

std::string lineNumber;

int lineNumberT = 1;
std::vector <std::string> KeyWords;
bool endComment = false;

int fw;
QColor tc;



IDE::IDE(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IDE){
    ui->setupUi(this);

    setWindowIcon(QIcon::fromTheme("C:/Users/g/Documents/QtProjects/MusicGenerator/images/iconMG.ico"));


    ui->actionrun->setIcon(QIcon::fromTheme("C:/Users/g/Documents/QtProjects/MusicGenerator/icon/run.png"));
    ui->actionCompile->setIcon(QIcon::fromTheme("C:/Users/g/Documents/QtProjects/MusicGenerator/icon/martillo.png"));

    ui->negra->setIcon(QIcon::fromTheme("C:/Users/g/Documents/QtProjects/MusicGenerator/images/negra.png"));
    ui->blanca->setIcon(QIcon::fromTheme("C:/Users/g/Documents/QtProjects/MusicGenerator/images/blanca.png"));
    ui->corchea->setIcon(QIcon::fromTheme("C:/Users/g/Documents/QtProjects/MusicGenerator/images/corchea.png"));
    ui->semicorchea->setIcon(QIcon::fromTheme("C:/Users/g/Documents/QtProjects/MusicGenerator/images/semicorchea.png"));
    ui->corcheaDoble->setIcon(QIcon::fromTheme("C:/Users/g/Documents/QtProjects/MusicGenerator/images/corcheadoble.png"));
    ui->silencio->setIcon(QIcon::fromTheme("C:/Users/g/Documents/QtProjects/MusicGenerator/images/silencio.png"));


    ui->textEdit->installEventFilter(this);
    ui->musicW->installEventFilter(this);
    ui->lineTextEdit->insertPlainText("0\n");


    //musicSheet-Editor
    ui->musicW->setVisible(false);



    //Menu Bar Actions
    connect(ui->actionrun, SIGNAL(triggered(bool)), this, SLOT(on_actionrun_triggered()));
    connect(ui->actionCompile, SIGNAL(changed()), this, SLOT(on_actionCompile_triggered()));
    connect(ui->actionOpen, SIGNAL(toggled(bool)), this, SLOT(on_actionOpen_triggered()));
    connect(ui->actionMusic_Sheet, SIGNAL(toggled(bool)), this, SLOT(on_actionMusic_Sheet_triggered()));
    connect(ui->actionSave_File, SIGNAL(toggled(bool)), this, SLOT(on_actionSave_File_triggered()));



    //Edit
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(veryKeywords()));



}


bool IDE::eventFilter(QObject *watched, QEvent *event){
    if (watched == ui->textEdit){
        if (event->type() == QEvent::KeyPress){
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Return){
                lineNumber = std::to_string(lineNumberT) + "\n";
                ui->lineTextEdit->insertPlainText(QString::fromStdString(lineNumber));
                lineNumberT += 1;
                //ui->textEdit->insertPlainText("\n");
            }
            if (keyEvent->key() == Qt::Key_Backspace){
                disconnect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(veryKeywords()));
                //std::string linea = ui->lineTextEdit->toPlainText();
                QTextCursor cursor = ui->textEdit->textCursor();
                cursor.select(QTextCursor::LineUnderCursor);
                QString word = cursor.selectedText();

                int lengthText = ui->textEdit->toPlainText().length();
                int posCursor = cursor.position();

                qInfo() << "word: "  << word;
                qInfo() << "length text: " << lengthText;
                qInfo() << "cursor position: " << posCursor;
                qInfo() << "linea actual: " << lineNumberT-1;

                if ((word == "") && (lengthText == posCursor)){
                   ui->lineTextEdit->setText("");

                   for (int i = 0; i < (lineNumberT-1); i++){
                       ui->lineTextEdit->insertPlainText(QString::fromStdString(std::to_string(i) + "\n"));
                   }
                   lineNumberT = lineNumberT-1;
                   if(lineNumberT < 0){
                       lineNumberT = 0;
                   }
                }

            }
            else{
                connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(veryKeywords()));
            }
        }
    }
    if (watched == ui->musicW){
        if (event->type() == QEvent::MouseButtonPress){
            QMouseEvent *mEvent = static_cast<QMouseEvent*>(event);
            if(mEvent->button() == Qt::LeftButton){
               qInfo() << ui->line01->x() << ui->line01->whatsThis() << ui->line01->isWindow();

            }
        }

    }
    return QMainWindow::eventFilter(watched, event);
}




void IDE::on_actionCompile_triggered(){
    //qInfo() << ui->textEdit->toPlainText();
    ui->consoleTextW->clear();
    ui->consoleTextW->appendPlainText(QString::fromStdString(">> Compile process"));
    ofstream codeFile;
    codeFile.open ("Fcode.mg");
    ui->consoleTextW->appendPlainText(QString::fromStdString(">> ... \n>> ..."));
    codeFile << ui->textEdit->toPlainText().toStdString();
    codeFile.close();
    ui->consoleTextW->appendPlainText(QString::fromStdString(">> Completed"));
}


void IDE::veryKeywords(){

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.select(QTextCursor::WordUnderCursor);
    QString word = cursor.selectedText();

    if (word == "Def"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "SET"){
        insertKeywords(word, cursor, "#B40486");
    }
    if (word == "Principal"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "Loop"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "IniLoop"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "FinLoop"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "Blak"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "Neg"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "Corch"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "IniComp"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "FinComp"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "EnCaso"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "Contrario"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "FinEnCaso"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "Ejecute"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "Silenc"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "Entonces"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "IniMusica"){
        insertKeywords(word, cursor, "#B40486");
    }
    if (word == "FinMusica"){
        insertKeywords(word, cursor, "#B40486");
    }



    else{
        QTextCursor cursorLine = ui->textEdit->textCursor();
        cursorLine.select(QTextCursor::LineUnderCursor);
        QString line = cursorLine.selectedText();
        if ( line == "/* " ){
            fw = ui->textEdit->fontWeight();
            tc = ui->textEdit->textColor();


            QTextCharFormat format(cursorLine.charFormat());
            format.setForeground(QColor(QString::fromStdString("#42F453")));
            cursorLine.insertText(line + "  ", format);
            endComment = false;
        }
        else if (line.contains("*/")){
            endComment = true;
            ui->textEdit->setFontWeight( fw );
            ui->textEdit->setTextColor( tc );
        }
    }



}

void IDE::insertKeywords(QString words, QTextCursor cursors, std::string color){
    int fw = ui->textEdit->fontWeight();
    QColor tc = ui->textEdit->textColor();

    QTextCharFormat format(cursors.charFormat());
    format.setForeground(QColor(QString::fromStdString(color)));
    cursors.insertText(words + " ", format);

    // restore

    ui->textEdit->setFontWeight( fw );
    ui->textEdit->setTextColor( tc );
}




IDE::~IDE(){
    delete ui;
}


void IDE::on_actionMusic_Sheet_triggered(){
    ui->musicW->setVisible(true);
    ui->textEdit->insertPlainText("IniMusica;");

}




void IDE::on_actionrun_triggered(){
   int result = system("bison --version");
    qInfo() << system("explorer.exe");
   //printf(result);

}




void IDE::on_action_Connection_triggered(){
    ui->consoleTextW->clear();
    Client cliente = Client();
    ui->consoleTextW->appendHtml(QString::fromStdString(cliente.startClient()));


}

void IDE::on_actionView_Console_triggered(){
    if (ui->consoleW->isVisible()){
        ui->consoleW->setVisible(false);
    }else{
        ui->consoleW->setVisible(true);
    }

}

void IDE::on_actionOpen_triggered(){
    QFileDialog dialogFileMG(this);
    QString pathFileMG = dialogFileMG.getOpenFileName(this,tr("Open File Music Generator"), "/Users/g/Documents",tr("Files (*.mg)"));

    QFile fileMG(pathFileMG);

    fileMG.open(QFile::ReadOnly | QFile::Text);

    QTextStream ReadFile(&fileMG);
    ui->textEdit->setText(ReadFile.readAll());

}

void IDE::on_actionSave_File_triggered(){
    QFileDialog dialogFileMG(this);
    QString pathFileMG = dialogFileMG.getSaveFileName(this, tr("Save File Music Generator"), "/Users/g/Documents",tr("Files (*.mg)"));

    ofstream codeFile;
    codeFile.open (pathFileMG.toStdString());
    codeFile << ui->textEdit->toPlainText().toStdString();
    codeFile.close();

}
