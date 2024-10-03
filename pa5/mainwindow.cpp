#include "mainwindow.h"
#include "ui_mainwindow.h"

//단어 배열
QString easy_words[30]= {"명징","직조", "갈증","비행기","나흗날","비둘기",
"옹달샘", "줄이다", "거울", "집오리", "물리학", "토마토", "올리브", "은박지",
"문지방", "물병", "양치질", "어린이", "집무실", "달빛", "다르다", "부고", "낫",
"서당", "참외", "사다리", "천지", "인바디", "어금니", "추격"};

//단어 배열
QString crazy_words[10]= {"숨마쿰라우데", "우거지다", "토지소유권", "하염없다", "도톰하다",
                          "넓적부리", "타란티노", "방울토마토", "객체지향수업", "컴퓨터공학과" };


MainWindow::MainWindow(QWidget *parent) // 생성자
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    time = 30, score = 0;
    timer = new QTimer(this);


    connect(timer, SIGNAL(timeout()), this, SLOT(updatetime()));
    connect(timer, SIGNAL(timeout()), this, SLOT(word_set()));
    connect(timer, SIGNAL(timeout()), this, SLOT(word_show()));
    connect(timer, SIGNAL(timeout()), this, SLOT(check()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updatescore()));
    timer->start(1000); // 1초 간격으로 위 함수 계속 돌려줌.


    // ui 셋팅 및 display

    ui->setupUi(this);
    ui->timeLeft->setText("TimeLeft");
    ui->Score->setText("Score");
    ui->lcdScore->display(score);
    ui->textedit->installEventFilter(this);

}

void MainWindow::setmsgbox(){ // quitgame messagebox 세팅해주는 함수

    quitgame.setIcon(QMessageBox::Question);
    quitgame.setWindowTitle("Time Out");
    QString text = "Your Score is " + QString::number(score) + ".\nDo you want to try again?";
    quitgame.setText(text);
    quitgame.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    quitgame.setDefaultButton(QMessageBox::Yes);


}

MainWindow::~MainWindow() // 소멸자, 별도로 구현하진 않음
{
    delete ui;
}


void MainWindow::updatetime() // 시간 업데이트해주는 함수
{
    if(time>=1){
    ui->lcdTime->display(time);
    time--; //기본적으로 1초 줄어듦.
    }

    else ui->lcdTime->display(time);
}

void MainWindow::updatescore() // 점수 업데이트해주는 함수
{

    if(cur_idx==-1) {
       ui->lcdScore->display(score);
       return;

    }

    if(cur_idx==0){ // word1과 matching된 경우

        if(iscrazy[0]==true) score+= 15;
        else score+=10;

        isfill[0] = false;
        ui->word1->clear();
        cur_idx=-1;
        word_count--;
    }

    if(cur_idx==1){ // word2과 matching된 경우

        if(iscrazy[1]==true) score+= 15;
        else score+=10;

        isfill[1] = false;
        ui->word2->clear();
        cur_idx=-1;
        word_count--;
    }

    if(cur_idx==2){ // word3과 matching된 경우

        if(iscrazy[2]==true) score+= 15;
        else score+=10;

        isfill[2] = false;
        ui->word3->clear();
        cur_idx=-1;
        word_count--;
    }

    if(cur_idx==3){ // word4과 matching된 경우

        if(iscrazy[3]==true) score+= 15;
        else score+=10;

        isfill[3] = false;
        ui->word4->clear();
        cur_idx=-1;
        word_count--;
    }

    if(cur_idx==4){ // word5과 matching된 경우

        if(iscrazy[4]==true) score+= 15;
        else score+=10;

        isfill[4] = false;
        ui->word5->clear();
        cur_idx=-1;
        word_count--;
    }

    if(cur_idx==5){ // word6과 matching된 경우

        if(iscrazy[5]==true) score+= 15;
        else score+=10;

        isfill[5] = false;
        ui->word6->clear();
        cur_idx=-1;
        word_count--;
    }


   ui->lcdScore->display(score);
}



void MainWindow:: word_set(){ //현재 단어가 몇 개 있는지 확인하여 단어를 새로 추가해주는 함수

    int idx;

    if(word_count == 6) return;

    int easy_word_idx, crazy_word_idx, is_crazy;

    for(int i=0; i<6; i++){

        if(isfill[i] == false){ //앞의 인덱스부터 채움

            idx = i;
            isfill[i] = true;
            word_count++;
            break;

        }
    }

    easy_word_idx = 0; crazy_word_idx = 0; is_crazy = 0;
    auto random = QRandomGenerator::global()->generate();
    srand(random); //시드 정해줌

    QString temp = "";

        is_crazy = rand() % 5;

        if(is_crazy==1){    //is_crazy가 1일 떄만 ,즉 20%의 확률

            crazy_word_idx = rand()%10;
            temp = crazy_words[crazy_word_idx];

            int x = (rand() % 600) + 100; //x: 랜덤 위치(100~699 범위)

            switch(idx+1) {

            case 1:
                ui->word1->setText(temp); // 단어 이름 세팅
                ui->word1->move(x, 60); // 위치 초기화
                ui->word1->show();
                iscrazy[0] = true;
                break;

            case 2:
                ui->word2->setText(temp);
                ui->word2->move(x, 60);
                ui->word2->show();
                iscrazy[1] = true;
                break;

            case 3:
                ui->word3->setText(temp);
                ui->word3->move(x, 60);
                ui->word3->show();
                iscrazy[2] = true;
                break;

            case 4:
                ui->word4->setText(temp);
                ui->word4->move(x, 60);
                ui->word4->show();
                iscrazy[3] = true;
                break;

            case 5:
                ui->word5->setText(temp);
                ui->word5->move(x, 60);
                ui->word5->show();
                iscrazy[4] = true;
                break;

            case 6:
                ui->word6->setText(temp);
                ui->word6->move(x, 60);
                ui->word6->show();
                iscrazy[5] = true;
                break;



            }


        }


        else{

            easy_word_idx = rand()%30; // (0~29) 범위
            temp = easy_words[easy_word_idx];

            int x = (rand() % 600) + 100;

            switch(idx+1) {

            case 1:
                ui->word1->setText(temp);
                ui->word1->move(x, 60);
                iscrazy[0] = false;

                break;

            case 2:
                ui->word2->setText(temp);
                ui->word2->move(x, 60);
                iscrazy[1] = false;

                break;

            case 3:
                ui->word3->setText(temp);
                ui->word3->move(x, 60);
                iscrazy[2] = false;

                break;

            case 4:
                ui->word4->setText(temp);
                ui->word4->move(x, 60);
                iscrazy[3] = false;
                break;

            case 5:
                ui->word5->setText(temp);
                ui->word5->move(x, 60);
                iscrazy[4] = false;

                break;

            case 6:
                ui->word6->setText(temp);
                ui->word6->move(x, 60);
                iscrazy[5] = false;

                break;

        }

        }



}

void MainWindow::word_show(){ //단어의 위치를 조정해가며 보여주는 함수


    int down = 20; // 초당 20씩 내려가면 적당함
    int crazy_down = down*1.5; // 1.5배 ㅃㅏ르다

    if(isfill[0]== true) {

        if(iscrazy[0]==true){
            if(ui->word1->y() <= 220) ui->word1->move(ui->word1->x(), ui->word1->y()+crazy_down);
            else ui->word1->move(ui->word1->x(), ui->word1->y()+down); // 중간 아래부터는 일반 속도
            ui->word1->setStyleSheet("color: red;"); //색상 빨간색으로 설정

        }

        else {
            ui->word1->move(ui->word1->x(), ui->word1->y()+down);
            ui->word1->setStyleSheet("color: black;");  //색상 검정색으로 다시 설정
        }
        ui->word1->show();
    }

    if(isfill[1]== true) {

        if(iscrazy[1]==true){
            if(ui->word2->y() <= 220) ui->word2->move(ui->word2->x(), ui->word2->y()+crazy_down);
            else ui->word2->move(ui->word2->x(), ui->word2->y()+down);
            ui->word2->setStyleSheet("color: red;");

        }

        else {
            ui->word2->move(ui->word2->x(), ui->word2->y()+down);
            ui->word2->setStyleSheet("color: black;");
      }
        ui->word2->show();
    }

    if(isfill[2]== true) {

        if(iscrazy[2]==true){
            if(ui->word3->y() <= 220) ui->word3->move(ui->word3->x(), ui->word3->y()+crazy_down);
            else ui->word3->move(ui->word3->x(), ui->word3->y()+down);
            ui->word3->setStyleSheet("color: red;");

        }

        else {
            ui->word3->move(ui->word3->x(), ui->word3->y()+down);
            ui->word3->setStyleSheet("color: black;");
        }
        ui->word3->show();
    }

    if(isfill[3]== true) {

        if(iscrazy[3]==true){
            if(ui->word4->y() <= 220) ui->word4->move(ui->word4->x(), ui->word4->y()+crazy_down);
            else ui->word4->move(ui->word4->x(), ui->word4->y()+down);
            ui->word4->setStyleSheet("color: red;");

        }

        else {
            ui->word4->move(ui->word4->x(), ui->word4->y()+down);
            ui->word4->setStyleSheet("color: black;");
        }
        ui->word4->show();
    }

    if(isfill[4]== true) {

        if(iscrazy[4]==true){
            if(ui->word5->y() <= 220) ui->word5->move(ui->word5->x(), ui->word5->y()+crazy_down);
            else ui->word5->move(ui->word5->x(), ui->word5->y()+down);
            ui->word5->setStyleSheet("color: red;");

        }

        else {
            ui->word5->move(ui->word5->x(), ui->word5->y()+down);
            ui->word5->setStyleSheet("color: black;");
        }
        ui->word5->show();
    }

    if(isfill[5]== true) {

        if(iscrazy[5]==true){
            if(ui->word6->y() <= 220) ui->word6->move(ui->word6->x(), ui->word6->y()+crazy_down);
            else ui->word6->move(ui->word6->x(), ui->word6->y()+down);
            ui->word6->setStyleSheet("color: red;");

        }

        else {
            ui->word6->move(ui->word6->x(), ui->word6->y()+down);
            ui->word6->setStyleSheet("color: black;");
        }
        ui->word6->show();
    }

}

void MainWindow::check(){ //단어의 속도, 위치 등을 체크해서 재조정해주는 함수

    if(time==0) {
        ui->lcdScore->display(time);
        ui->lcdScore->display(score);
        endgame();
    }

    if(isfill[0]== true) {
        int y1 = ui->word1->y();
        if(y1 >= 380){

            isfill[0] = false;
            iscrazy[0] = false;
            word_count--;
            time-=3;
            if(time<0) time = 0;
            ui->word1->clear();


        }
    }

    if(isfill[1]== true) {
        int y2 = ui->word2->y();
        if(y2 >= 380){

            isfill[1] = false;
            iscrazy[1] = false;
            word_count--;
            time-=3;
            if(time<0) time = 0;
            ui->word2->clear();


        }
    }

    if(isfill[2]== true) {
        int y3 = ui->word3->y();
        if(y3 >= 380){

            isfill[2] = false;
            iscrazy[2] = false;
            word_count--;
            time-=3;
            if(time<0) time = 0;
            ui->word3->clear();


        }
    }

    if(isfill[3]== true) {
        int y4 = ui->word4->y();
        if(y4 >= 380){

            isfill[3] = false;
            iscrazy[3] = false;
            word_count--;
            time-=3;
            if(time<0) time = 0;
            ui->word4->clear();


        }
    }

    if(isfill[4]== true) {
        int y5 = ui->word5->y();
        if(y5 >= 380){

            isfill[4] = false;
            iscrazy[4] = false;
            word_count--;
            time-=3;
            if(time<0) time = 0;
            ui->word5->clear();


        }
    }

    if(isfill[5]== true) {
        int y6 = ui->word6->y();
        if(y6 >= 380){

            isfill[5] = false;
            iscrazy[5] = false;
            word_count--;
            time-=3;
            if(time<0) time = 0;
            ui->word6->clear();


        }
    }

}

void MainWindow::endgame(){ //게임을 끝낼 지 결정하는 함수

    setmsgbox();
    int ret = quitgame.exec();

    switch (ret){

    case QMessageBox::Yes: //yes면 다시 시작
        Reloadgame(); //게임을 다시 시작하는 함수
        break;

    case QMessageBox::No:
        exit(0); //프로그램 종료
        break;

    }
}

void MainWindow::Reloadgame(){ //게임을 다시 시작하는 함수

//멤버 변수 초기화
    time = 30;
    score = 0;
    word_count = 0;
    cur_idx = -1;
    cur_word=  "";

    if(isfill[0]==true) ui->word1->clear();
    if(isfill[1]==true) ui->word2->clear();
    if(isfill[2]==true) ui->word3->clear();
    if(isfill[3]==true) ui->word4->clear();
    if(isfill[4]==true) ui->word5->clear();
    if(isfill[5]==true) ui->word6->clear();

    for(int i=0; i<6; i++){
        isfill[i] = false;
        iscrazy[i] = false;
    }
}



bool MainWindow::eventFilter(QObject *watched, QEvent *event) //엔터를 받아오기 위한 eventfilter
{

    if( event->type() == QEvent::KeyPress){
        QKeyEvent *key = static_cast <QKeyEvent*> (event);

        if(key->key()== Qt::Key_Enter || key->key()== Qt::Key_Return){

            cur_word = ui->textedit->text();

            match(); //match 함수 호출

            ui->textedit->clear(); // enter 호출되면 비워줌

            return true;
        }
    }
    return QObject::eventFilter(watched, event);
}

void MainWindow::match(){ //현재 들어온 단어(cur_word)와 창에 떠 있는 단어를 비교해서 일치하는 단어의 index를 리턴하는 함수

    cur_idx = -1;
    int cur_y = -1;

    if(cur_word == ui->word1->text()){

        if(cur_y < ui->word1->y()) {
            cur_y = ui->word1->y();
            cur_idx = 0;
        }

    }

    if(cur_word == ui->word2->text()){

        if(cur_y < ui->word2->y()) {
            cur_y = ui->word2->y();
            cur_idx = 1;
        }

    }

    if(cur_word == ui->word3->text()){

        if(cur_y < ui->word3->y()) {
            cur_y = ui->word3->y();
            cur_idx = 2;
        }

    }

    if(cur_word == ui->word4->text()){

        if(cur_y < ui->word4->y()) {
            cur_y = ui->word4->y();
            cur_idx = 3;
        }

    }

    if(cur_word == ui->word5->text()){

        if(cur_y < ui->word5->y()) {
            cur_y = ui->word5->y();
            cur_idx = 4;
        }

    }

    if(cur_word == ui->word6->text()){

        if(cur_y < ui->word6->y()) {
            cur_y = ui->word6->y();
            cur_idx = 5;
        }

    }


}


