#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化
    time1 = 20;
    timer=nullptr;
    //one = true;
    index = 0;
    count = 0;
    task_num = 0;
    oper_num = 0;
    max_num = 0;
    task_num_0 = 0;
    result = -1;
    result_str = "null";
    question = "";
    answer = -1;
    answer_str = "null";
    wrong_idd =-1;
    correct_num = 0;
    correct_rate = 0;
    calc_type_int = 0;

    calc_type = new QButtonGroup(this);
    calc_type->addButton(ui->radioButton,0);
    calc_type->addButton(ui->radioButton_2,1);
    calc_type->addButton(ui->radioButton_3,2);
    ui->radioButton->setChecked(true);

    opr_num = 5;
    min_num = 0;
    max_num =100;
    accuracy = 2;
    type_int = 0;
    flag_choose_advance = false;

    //API
#ifdef CORE_MRC
    core = new fomularCore;
#endif

#ifdef CORE_LJW
    out_api = new string;
    res_api = new string;
#endif
    //END OF API
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete main_stack_widget;
}

void MainWindow::on_pushButton_clicked()  //点击开始答题按钮
{
    if(!flag_choose_advance){   //高级选项设置
        opr_num = 5;
        min_num = 0;
        max_num =100;
        accuracy = 0;
        type_int = 0;
        //calc_type_int = 0;
    }
    else{
        opr_num = dlg3->get_opr_num();
        min_num = dlg3->get_min_num();
        max_num = dlg3->get_max_num();
        accuracy = dlg3->get_accuracy();
        type_int = dlg3->get_type_int();
    }
    flag_choose_advance = false;


    //强迫性填写两个单元
    if(!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() /*&& !ui->lineEdit_3->text().isEmpty()*/){
        task_num = ui->lineEdit->text().toInt();
        task_num_0=task_num;
        oper_num = ui->lineEdit_2->text().toInt();
        //max_num = ui->lineEdit_3->text().toInt();
    }
    else{
        QMessageBox *box_ = new QMessageBox(this);
        box_->warning(this, tr("温馨提示"), tr("请填写题目数，最多运算次数！"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }

    //选择运算符种类
    if(ui->radioButton_3->isChecked()){
        calc_type_int = 2;
    }
    else if(ui->radioButton_2->isChecked()){
        calc_type_int =1;
    }
    else {
        calc_type_int =0;
    }




    //API


#ifdef CORE_MRC
    if(calc_type_int == 2){  //加减乘除乘方
        ops_api = "+-*/^()";
    }
    else if(calc_type_int == 1){  //加减乘除
        ops_api = "+-*/()";
    }
    else{  //加减
        ops_api = "+-()";
    }

    if(type_int == 2){  //分数
        fraction = true;
    }
    else if(type_int == 1){  //小数
        fraction = false;
    }
    else{  //整数
        fraction = false;
        accuracy = 0;
    }

    /*
     *API主要调用
     * setting设置
     * out_api为返回的数组
     * res_api为返回的答案
     */
    count_api =0;
    core->setting(task_num_0, oper_num, min_num, max_num, ops_api, fraction, accuracy);
    out_api = core->Generate();
    res_api = core->getRes();
    core->Clear();
#endif

#ifdef CORE_LJW
    if(calc_type_int == 2){  //加减乘除乘方
        has_mul_div = true;
        has_power = true;
    }
    else if(calc_type_int == 1){  //加减乘除
        has_mul_div = true;
        has_power = false;
    }
    else{  //加减
        has_mul_div = false;
        has_power = false;
    }

    if(type_int == 2){  //分数
        has_fraction = true;
        has_real = false;
        accuracy = 0;
    }
    else if(type_int == 1){  //小数
        has_fraction = false;
        has_real = true;
    }
    else{  //整数
        has_fraction = false;
        has_real = false;
        accuracy = 0;
    }
    set_setting(oper_num, max_num, accuracy, has_fraction, has_real, has_mul_div, has_power);
    //generate(out_api,res_api);
#endif

    //END OF API


    //转换到答题界面
    count = ui->stackedWidget1->count();
    index = ui->stackedWidget1->currentIndex();
    index++;
    if(index == count){
        index =0;
    }
    //QString qstr="asdasd";
    ui->stackedWidget1->setCurrentIndex(index);

    ui->label_2->setText(QString::number(task_num_0-task_num+1));

    question = "the_first_q";

    //API
    //设置题目和答案
#ifdef CORE_MRC
    question = out_api[count_api];
    answer_str = res_api[count_api];
    count_api++;
#endif

#ifdef CORE_LJW
    generate(out_api,res_api);
    question = *out_api;
    answer_str = *res_api;
#endif
    //END OF API



    //显示题目
    ui->textBrowser->setPlainText(QString::fromStdString(question));//输入题目

    //启动计时
    timer= new QTimer;
    time1 = 20;
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
    timer->start(1000); //每次计时1s，1s结束后触发槽timeout()
}

//static int time1 = 20 ;

void MainWindow::timeout(){

    if(time1!=0){ //如果时间还没到20s
        time1--;
        ui->lcdNumber->display(QString::number(time1,10));//显示十进制时间
    }
    else{
        result = -1; //不使用，使用result_str
        result_str = "null"; //因为时间到，所以result = null
        wrong_idd = task_num_0-task_num+1; //错题序号

        //task_num--;

        wrong_answers.open("./wrong_answer.txt",ios::app);    //添加到错题本
        wrong_answers << wrong_idd <<"\n"<< question << "\n" << result_str << "\n" << answer_str << endl ;
        wrong_answers.close();

        result =-1;              //维护
        result_str = "null";
        question = "null";
        answer = -1;
        answer_str = "null";
        wrong_idd = -1;

        //生成时间到的提示框
        QMessageBox *box = new QMessageBox(this);

        box->warning(this,tr("温馨提示"),tr("时间到！"),QMessageBox::Yes,QMessageBox::Yes);


            task_num--;
            //进入下一题!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

            if(task_num != 0){
                /*question = "time_out_ok?";
                //answer = 输入答案---------------------
                answer = 2;
                answer_str = "";*/

                //API
#ifdef CORE_MRC
    question = out_api[count_api];
    answer_str = res_api[count_api];
    count_api++;
#endif

#ifdef CORE_LJW
    generate(out_api,res_api);
    question = *out_api;
    answer_str = *res_api;
#endif
                //END OF API

                //显示新一题
                ui->label_2->setText(QString::number(task_num_0-task_num+1));
                ui->textBrowser->setPlainText(QString::fromStdString(question));
                ui->textEdit->clear();
                time1 = 20;
            }
            else{
                //如果已经答完所有题
                timer->stop();

                //计算正确率
                correct_rate = (double)correct_num / (double)task_num_0 ;

                //生成历史记录
                history.open("./history.txt",ios::app);
                history << task_num_0 << "\n" << correct_num << "\n" << correct_rate << endl;
                history.close();

                //生成评价分享
                share.open("./share.txt",ios::out);
                if(correct_rate > 0.95){
                    share << u8"You've finished " << task_num_0 << u8" tasks. " << u8"Among them, " << correct_num << u8" are correct! " << u8"Congratulations! You get a 4.3" <<endl ;
                }
                else if(correct_rate > 0.9){
                    share << u8"You've finished " << task_num_0 << u8" tasks. " << u8"Among them, " << correct_num << u8" are correct! " << u8"Good job! You get a 4.0" <<endl ;
                }
                else if(correct_rate > 0.85){
                    share << u8"You've finished " << task_num_0 << u8" tasks. " << u8"Among them, " << correct_num << u8" are correct! " << u8"Ah-ha! You get a 3.7" <<endl ;
                }
                else if(correct_rate > 0.82){
                    share << u8"You've finished " << task_num_0 << u8" tasks. " << u8"Among them, " << correct_num << u8" are correct! " << u8"Come on! You get a 3.3" <<endl ;
                }
                else{
                    share << u8"You've finished " << task_num_0 << u8" tasks. " << u8"Among them, only " << correct_num << u8" are correct! " << u8"Just ask you textbook for some help! " <<endl ;
                }
                share.close();

                //转换到答题结束页面
                index++;
                if(index == count){
                    index =0;
                }
                ui->stackedWidget1->setCurrentIndex(index);
                ui->textBrowser_3->setPlainText(QString::number(task_num_0));
                ui->textBrowser_2->setPlainText(QString::number(correct_num));

                //维护
                task_num = 0;
                oper_num = 0;
                max_num = 0;
                task_num_0 = 0;
                result = -1;
                result_str = "null";
                question = "null";
                answer = -1;
                answer_str ="null";
                wrong_idd =-1;
                correct_num = 0;
                correct_rate = 0;
                ui->textEdit->clear();
            }
    }

}

void MainWindow::on_actionewwewe_triggered()//点击了新建答题
{
    //如果计时器打开，则停止
    if(timer && timer->isActive())
        timer->stop();

    //转到生成界面
    index = 1;
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->stackedWidget1->setCurrentIndex(index);
    //}
}

void MainWindow::on_actioncuotiben_triggered() //点击错题本
{
    Dialog1 *dlg = new Dialog1(this);
    dlg->exec();
}

void MainWindow::on_actionlishijiu_triggered()//点击历史记录
{
    Dialog2 *dlg = new Dialog2(this);
    dlg->exec();
}

void MainWindow::on_actionshuchuchengji_triggered()//点击输出成绩
{
    QMessageBox *fucking_share = new QMessageBox;
    fucking_share->warning(this,tr("温馨提示"),tr("你的分享文件在答题文件的文件夹下噢~"),QMessageBox::Yes,QMessageBox::Yes);
}

void MainWindow::on_pushButton_2_clicked() //点击下一题
{

    //result = ui->textEdit->toPlainText().toDouble();
    //获取结果
    result_str = ui->textEdit->toPlainText().toStdString();

    while(result_str[result_str.length()-1] == '\n' || result_str[result_str.length()-1] == ' '){
        result_str.pop_back();
    }

    if(result_str.compare(answer_str) != 0){           //是否答对，如否加入错题本
        wrong_answers.open("./wrong_answer.txt",ios::app);
        wrong_idd = task_num_0-task_num+1;
        wrong_answers << wrong_idd <<"\n"<< question << "\n" << result_str <<"\n"<< answer_str << endl ;
        wrong_answers.close();
    }
    else{
        correct_num++;
    }

    //维护
    result =-1;
    result_str ="null";
    question = "null";
    answer = -1;
    answer_str = "null";
    wrong_idd=-1;


    task_num--;
    //进入下一题



    if(task_num != 0){ //如果没有全部答完
        time1=20;
        /*question = "aaaaaaaaaaaaaaaaaa";
        //answer = "输入答案-------------------"
        answer = 2;
        answer_str= "null";*/

        //API
#ifdef CORE_MRC
    question = out_api[count_api];
    answer_str = res_api[count_api];
    count_api++;
#endif

#ifdef CORE_LJW
    generate(out_api,res_api);
    question = *out_api;
    answer_str = *res_api;
#endif
        //END OF API

        //输出下一题
        ui->label_2->setText(QString::number(task_num_0-task_num+1));
        ui->textBrowser->setPlainText(QString::fromStdString(question));
        ui->textEdit->clear();
    }
    else{            //答题结束
        timer->stop();

        correct_rate = (double)correct_num / (double)task_num_0 ;

        //生成历史记录
        history.open("./history.txt",ios::app);
        history << task_num_0 << "\n" << correct_num << "\n" << correct_rate << endl;
        history.close();

        //生成评价分享
        share.open("./share.txt",ios::out);
        if(correct_rate > 0.95){
            share << u8"You've finished " << task_num_0 << u8" tasks. " << u8"Among them, " << correct_num << u8" are correct! " << u8"Congratulations! You get a 4.3" <<endl ;
        }
        else if(correct_rate > 0.9){
            share << u8"You've finished " << task_num_0 << u8" tasks. " << u8"Among them, " << correct_num << u8" are correct! " << u8"Good job! You get a 4.0" <<endl ;
        }
        else if(correct_rate > 0.85){
            share << u8"You've finished " << task_num_0 << u8" tasks. " << u8"Among them, " << correct_num << u8" are correct! " << u8"Ah-ha! You get a 3.7" <<endl ;
        }
        else if(correct_rate > 0.82){
            share << u8"You've finished " << task_num_0 << u8" tasks. " << u8"Among them, " << correct_num << u8" are correct! " << u8"Come on! You get a 3.3" <<endl ;
        }
        else{
            share << u8"You've finished " << task_num_0 << u8" tasks. " << u8"Among them, only " << correct_num << u8" are correct! " << u8"Just ask you textbook for some help! " <<endl ;
        }
        share.close();

        //转到答题结束界面
        index++;
        if(index == count){
            index =0;
        }
        ui->stackedWidget1->setCurrentIndex(index);
        ui->textBrowser_3->setPlainText(QString::number(task_num_0));
        ui->textBrowser_2->setPlainText(QString::number(correct_num));

        task_num = 0;
        oper_num = 0;
        max_num = 0;
        task_num_0 = 0;
        result = -1;
        result_str = "null";
        question = "null";
        answer = -1;
        answer_str = "null";
        wrong_idd =-1;
        correct_num = 0;
        correct_rate = 0;
        ui->textEdit->clear();
    }
}

void MainWindow::on_pushButton_4_clicked()  //
{
    //如果计时器打开，则停止
    if(timer && timer->isActive())
        timer->stop();

    //转到生成界面
    index = 1;
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->stackedWidget1->setCurrentIndex(index);
    //}

    /*index++;
    if(index == count){
        index =0;
    }
    ui->stackedWidget1->setCurrentIndex(index);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    //ui->lineEdit_3->clear();*/
}

void MainWindow::on_pushButton_5_clicked()  //点击退出
{
    qApp->quit();
}

void MainWindow::on_pushButton_3_clicked()  //点击进入错题本
{
    Dialog1 *dlg = new Dialog1(this);
    dlg->exec();
}

void MainWindow::on_pushButton_6_clicked()  //点击高级选项
{
    flag_choose_advance = true;
    dlg3 = new Dialog3(this);
    dlg3->exec();
}

void MainWindow::get_arith(const string &arith){
    question = arith;
}

void MainWindow::get_ans(const string &ans){
    answer_str = ans;
}
