#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "header.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    //ui(new Ui::MainWindow)
{

    int i,j,k;
    int id;
    string s[5];
    string ss;
    initializeForum();
    button1 = new QPushButton("登陆", this);
    button2= new QPushButton("注册", this);
    button3= new QPushButton("确定", this);
    button4= new QRadioButton("管理员",this);

    button5=new QPushButton("C++语法学习",this);
    button6=new QPushButton("问题交流讨论",this);
    button7=new QPushButton("优秀代码展示",this);


    button5->setVisible(false);
    button6->setVisible(false);
    button7->setVisible(false);



    button9=new QPushButton("注销",this);
    button9->setVisible(false);
    line1= new QLineEdit(this);
    line2= new QLineEdit(this);

    passwordInput=new QLabel("密码:",this);

    userNameInput=new QLabel("用户名:",this);
    passwordInput->setVisible(true);
    userNameInput->setVisible(true);

    button3->setVisible(false);
    connect(button1, SIGNAL(clicked()), this, SLOT(ClickButton1()));
    connect(button2, SIGNAL(clicked()), this, SLOT(ClickButton2()));
    connect(button3, SIGNAL(clicked()), this, SLOT(ClickButton3()));
    connect(button9, SIGNAL(clicked()), this, SLOT(ClickButton9()));



    writePost=new QTextEdit(this);
    writePost->setVisible(false);


    writeComment=new QTextEdit(this);
    writeComment->setVisible(false);

    area=new QScrollArea(this);
    area->setVisible(false);
    paint=new QWidget(area);
    area->setWidget(paint);

    postwindow=new QLabel(paint);
    postTime=new QLabel(paint);
    commentshow=new QLabel(paint);

    PostUp=new QLabel(paint);
    PostContentShow=new QLabel(paint);
    PostTimeShow=new QLabel(paint);

    button8=new QPushButton("提交",this);
    button8->setGeometry(2200,1000,100,50);
    button8->setVisible(false);
    connect(button8, SIGNAL(clicked()), this, SLOT(ClickButton8()));

    button11=new QPushButton("提交",this);
    button11->setGeometry(2200,1000,100,50);
    button11->setVisible(false);
    connect(button11, SIGNAL(clicked()), this, SLOT(ClickButton7()));

    button10=new QPushButton("更换",this);
     connect(button10, SIGNAL(clicked()), this, SLOT(ClickButton12()));
     button10->setVisible(false);

     button12=new QPushButton("详细信息",this);
      connect(button12, SIGNAL(clicked()), this, SLOT(ClickButton14()));
      button12->setVisible(false);

    titleinsert=new QLineEdit(this);
    titleinsert->setGeometry(500,900,1700,100);
    titleinsert->setVisible(false);

    moderatorName=new QLabel(this);


     dialog=new QDialog();
     dialog->setVisible(false);
     linenewmoderator=new QLineEdit(dialog);
     linenewmoderator->setVisible(false);
     linenewmoderator->setGeometry(50,10,100,50);
     chanemoderator=new QPushButton("确定",dialog);
     chanemoderator->setGeometry(120,70,50,50);
     dialog->setFixedSize(300,150);

     connect(chanemoderator, SIGNAL(clicked()), this, SLOT(ClickButton13()));


     QPixmap pixmap("C:\\Users\\63176\\Documents\\forum\\sky2.jpg");
     QPalette palette=this->palette();
     palette.setBrush(QPalette::Background,QBrush(pixmap));
     this->setPalette(palette);




    writeComment ->setStyleSheet("background-color: rgb(255, 255, 255, 60);");
    writePost ->setStyleSheet("background-color: rgb(255, 255, 255, 60);");
     titleinsert->setStyleSheet("background-color: rgb(255, 255, 255, 60);");
     paint->setStyleSheet("background-color: rgb(255, 255, 255, 60);");
     area->setStyleSheet("background-color: rgb(255, 255, 255, 60);");

     defaultUserTime();


     line1->setGeometry(600,300,300,50);
     line2->setGeometry(600,400,300,50);
     button1->setGeometry(700,600,100,50);
     button2->setGeometry(700,700,100,50);
     button3->setGeometry(700,600,100,50);
     button4->setGeometry(1000,600,200,50);

     button5->setGeometry(20,500,300,50);
     button6->setGeometry(20,600,300,50);
     button7->setGeometry(20,700,300,50);

     passwordInput->setGeometry(550,400,50,50);
     userNameInput->setGeometry(550,300,50,50);
     writePost->setGeometry(500,1000,1700,400);
     writeComment->setGeometry(500,1000,1700,400);

     button8->setGeometry(2200,1000,100,50);  //提交按钮
     button10->setGeometry(550,200,50,50);    //更换版主按钮
     button11->setGeometry(2200,1000,100,50);  //提交按钮

     area->setGeometry(500,250,1700,660);
     //area->setGeometry(500,250,1700,550);
     //chanemoderator->setGeometry(120,70,50,50);  //

}



void MainWindow::initializeForum()
{
    int i,j,k;
    int id;
    string s[5];
    string ss;
    QFile file("users.txt");
    QTextCodec *codec = QTextCodec::codecForName("GBK");


    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }


    QByteArray line = file.readLine();
    line = file.readLine();

    for(i=0;i<3;i++)    //管理员初始化
    {
        for(j=0;j<3;j++)
        {
            QByteArray line = file.readLine();
            QString str(line);
            s[j] = str.toStdString();
            s[j] = s[j].substr(0,s[j].length() - 1);
        }
            Administrator u(s[0],s[1],s[2]);
            administrators.push_back(u);
            line = file.readLine();
     }


    line = file.readLine();
    for(i=0;i<3;i++)    //普通用户初始化
    {
        for(j=0;j<3;j++)
        {
            QByteArray line = file.readLine();
            QString str(line);
            s[j] = str.toStdString();
            s[j] = s[j].substr(0,s[j].length() - 1);
        }
        Ordinaryuser o(s[0],s[1],s[2]);
        ordinaryusers.push_back(o);
        line = file.readLine();
    }
     line = file.readLine();
    for(i=0;i<3;i++)    //版主初始化
    {
        for(j=0;j<3;j++)
        {
            QByteArray line = file.readLine();
            QString str(line);
            s[j] = str.toStdString();
            s[j] = s[j].substr(0,s[j].length() - 1);
        }
        Moderator o(s[0],s[1],s[2]);
        moderators.push_back(o);
        moderators[i].changeSection(i);
        line = file.readLine();
    }
    file.setFileName("configure.txt");


    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    line = file.readLine();

    for(i=0;i<3;i++)
    {
        QByteArray line = file.readLine();
        QString str=codec->toUnicode(line);
        qDebug()<<str<<endl;
        ss=str.toStdString();
        ss=ss.substr(0,ss.length() - 1);
        Section section(ss);
        sections.push_back(section);
    }
    line = file.readLine();   //跳过两行
    line = file.readLine();
    id=0;

    for(i=0;i<6;i++)     //读入帖子
    {
        for(j=0;j<4;j++)
        {
            QByteArray line = file.readLine();
            QString str=codec->toUnicode(line);
            s[j] = str.toStdString();
            s[j]=s[j].substr(0,s[j].length() - 1);
        }
        Post o(s[0],s[1],s[2],s[3],id);
        id++;
        posts.push_back(o);
        line = file.readLine();
    }
    line = file.readLine();
    id=0;
    for(i=0;i<12;i++)     //读入评论
    {
        for(j=0;j<3;j++)
        {
            QByteArray line = file.readLine();
            QString str=codec->toUnicode(line);
            s[j] = str.toStdString();
            s[j]=s[j].substr(0,s[j].length() - 1);
        }
        Comment o(s[0],s[1],s[2],id);
        id++;
        comments.push_back(o);
        line = file.readLine();
    }

    for(i=0;i<ordinaryusers.size();i++)
    {
        ordinaryusers[i].addAccusationtimes(2);
        ordinaryusers[i].changeLevel(1);
    }
    for(i=0;i<moderators.size();i++)
    {
        moderators[i].addAccusationtimes(2);
        moderators[i].changeLevel(1);
    }
    mapProduce();
}

void MainWindow::defaultUserTime()
{
    int i;
    string s="2018年10月20日";
    for(i=0;i<ordinaryusers.size();i++)
        ordinaryusers[i].changeLastOnlineTime(s);
    for(i=0;i<moderators.size();i++)
        moderators[i].changeLastOnlineTime(s);
    for(i=0;i<administrators.size();i++)
        administrators[i].changeLastOnlineTime(s);


}

void MainWindow::enterForum()
{
    moderatorName->setVisible(false);
    writePost->setVisible(false);
    writeComment->setVisible(false);

    line1->setVisible(true);
    line2->setVisible(true);
    button4->setVisible(true);
    line1->clear();
    line2->clear();
    titleinsert->setVisible(false);

    if(userkind==0)
        administrators[num].outUser();
    else if(userkind==1)
        ordinaryusers[num].outUser();
    else if(userkind==2)
        moderators[num].outUser();
    hidecommentandpost();
    area->setVisible(false);
    if(commentshow)
    commentshow->setVisible(false);
    q1->setVisible(false);
    userName->setVisible(false);;  //用户名字
    Id->setVisible(false);;   //ID号
    userkindpic->setVisible(false);;   //用户种类

    button1->setVisible(true);
    button2->setVisible(true);
    button5->setVisible(false);
    button6->setVisible(false);
    button7->setVisible(false);
    button8->setVisible(false);
    button9->setVisible(false);
    button10->setVisible(false);
    button11->setVisible(false);
    button12->setVisible(false);

    passwordInput->setVisible(true);
    userNameInput->setVisible(true);

}


void MainWindow::mapProduce()
{
    int i,j;
    int flag=1;
    j=0;
    for(i=0;i<3;i++)   //这个是将板块和帖子映射到一起
    {
        sections[i].changeposts(j);
        sections[i].changeposts(j+1);
        j=j+2;
    }
    j=0;
    for(i=0;i<6;i++)    //这个是将帖子和评论映射到一起
    {
        posts[i].changeComments(j);
        posts[i].changeComments(j+1);
        j=j+2;
    }


    for(i=0;i<posts.size();i++)  //这个是将用户和帖子映射到一起，用户分为版主和普通用户
    {
        for(j=0;j<ordinaryusers.size();j++)
        {
            if(ordinaryusers[j].getuserName()==posts[i].getuserName())
            {
                ordinaryusers[j].addPosts(posts[i].getID());
                break;
            }
        }
        for(j=0;j<moderators.size();j++)
        {
            if(moderators[j].getuserName()==posts[i].getuserName())
            {
                moderators[j].addPosts(posts[i].getID());
                break;
            }
        }
    }

    for(i=0;i<comments.size();i++)  //这个是将用户和评论映射到一起，用户分为版主和普通用户
    {
        for(j=0;j<ordinaryusers.size();j++)
        {
            if(ordinaryusers[j].getuserName()==comments[i].getuserName())
            {
                ordinaryusers[j].addComments(comments[i].getID());
                break;
            }
        }
        for(j=0;j<moderators.size();j++)
        {
            if(moderators[j].getuserName()==comments[i].getuserName())
            {
                moderators[j].addComments(comments[i].getID());
                break;
            }
        }
    }
    for(i=0;i<sections.size();i++)
    {
        sections[i].changeModerator(moderators[i].getuserName());
    }
}


void MainWindow::ClickButton1()   //登录确定
{
    int i;
    QString nameUser = line1->text();
    QString password = line2->text();
    int result=ifconform(nameUser.toStdString(),password.toStdString());
    if(result==0)
    {
        if(userkind==0)
            administrators[num].Online();
        else if(userkind==1)
            ordinaryusers[num].Online();
        else if(userkind==2)
            moderators[num].Online();
        startForum();
    }
    else if(result==1)
    {
        QLabel*text=new QLabel("用户不存在");  //弹出提示框注册成功
        text->setFixedSize(300,100);
        text->setVisible(true);
        qDebug()<<"用户不存在"<<endl;    //弹出一个输入错误框，让用户重新输入
    }
    else if(result==2)
    {
        QLabel*text=new QLabel("输入密码错误");  //弹出提示框注册成功
        text->setFixedSize(300,100);
        text->setVisible(true);
        qDebug()<<"密码输入错误"<<endl;   //提示用户是密码输入错误
    }

}



void MainWindow::startForum()   //进入论坛
{

    button1->setVisible(false);
    button2->setVisible(false);
    button3->setVisible(false);
    button4->setVisible(false);
    line1->setVisible(false);
    line2->setVisible(false);
    passwordInput->setVisible(false);
    userNameInput->setVisible(false);

    q1 =new QLabel(" <h1><<fontcolor=red>C++学习论坛欢迎您</font></h1>",this);
    QFont font ( "宋体" ,20, 75);
    q1->setFont(font);

    q1->setAlignment(Qt::AlignHCenter);
    q1->setVisible(true);
    q1->setGeometry(1000,100,1200,100);

    pe.setColor(QPalette::WindowText,Qt::red);
    q1->setPalette(pe);
    /*
    button5=new QPushButton("C++语法学习",this);
    button6=new QPushButton("问题交流讨论",this);
    button7=new QPushButton("优秀代码展示",this);

    button5->setGeometry(20,500,300,50);
    button6->setGeometry(20,600,300,50);
    button7->setGeometry(20,700,300,50);
    */

    button5->setVisible(true);
    button6->setVisible(true);
    button7->setVisible(true);
    button9->setVisible(true);

    button5->setObjectName(QString::number(0));
    button6->setObjectName(QString::number(1));
    button7->setObjectName(QString::number(2));
    connect(button5, SIGNAL(clicked()), this, SLOT(ClickButton5()));
    connect(button6, SIGNAL(clicked()), this, SLOT(ClickButton5()));
    connect(button7, SIGNAL(clicked()), this, SLOT(ClickButton5()));

    showUsers();

}


void MainWindow::showUsers()   //左上角显示用户信息
{
    string s,s1,s2,s3,s4;
    userName=new QLabel(this);
    Id=new QLabel(this);
    userkindpic=new QLabel(this);


    if(userkind==1)
    {
        ordinaryusers[num].getInfor(s3,s4);
        s1="UserName:"+s3;
        s2="Id:"+s4;
    }
    else if(userkind==0)
    {
        administrators[num].getInfor(s3,s4);
        s1="UserName:"+s3;
        s2="Id:"+s4;
    }
    else if(userkind==2)
    {
        moderators[num].getInfor(s3,s4);
        s1="UserName:"+s3;
        s2="Id:"+s4;
    }


    QString str=QString::fromStdString(s1);
    userName->setText(str);
    userName->setGeometry(50,50,300,50);
    userName->setVisible(true);

    str=QString::fromStdString(s2);
    Id->setText(str);
    Id->setGeometry(50,100,300,50);
    Id->setVisible(true);

    s="userKind:";
    if(userkind==1)
    s+="ordinaryuser";
    else if(userkind==2)
    s+="medorater";
    else if(userkind==0)
    s+="administrator";
    str=QString::fromStdString(s);
    userkindpic->setText(str);
    userkindpic->setGeometry(50,150,300,50);
    userkindpic->setVisible(true);

    button9->setGeometry(50,200,300,50);
    button12->setGeometry(50,300,300,50);
    button12->setVisible(true);





}

void MainWindow::ClickButton2()   //进入注册界面
{
    button1->setVisible(false);
    button2->setVisible(false);
    button3->setVisible(true);
}


void MainWindow::ClickButton5()   //进入某个板块下面
{

    //加上滚动界面
    int i;
    hidecommentandpost();
    //button8->setVisible(true);
    button11->setVisible(false);
    writeComment->setVisible(false);
    writePost->setVisible(true);
    titleinsert->setVisible(true);
    writePost->clear();
    titleinsert->clear();

    postwindow->setVisible(false);
    PostUp->setVisible(false);
    PostTimeShow->setVisible(false);
    postTime->setVisible(false);
    commentshow->setVisible(false);
    if(userkind!=0)
    button8->setVisible(true);

    //area->setGeometry(500,250,1700,660);
    area->setVisible(true);
    paint->setGeometry(0,0,1700,400);
    area->setWidget(paint);
   QObject *object = QObject::sender();
   QPushButton *push_button = qobject_cast<QPushButton *>(object);
   int index;
   if(push_button)
   {
       QString object_name = push_button->objectName();
       index = object_name.toInt();
   }
   sectionnum=index;   //记录当前版块号
   showModeratorName();
   postbuttons.clear();
   showPosts();
}

void MainWindow::ClickButton6()    //进入某个帖子下面
{
    int i;
    string s;
    titleinsert->setVisible(false);
    writePost->setVisible(false);
    hidecommentandpost();
    button8->setVisible(false);
    QObject *object = QObject::sender();
    QPushButton *push_button = qobject_cast<QPushButton *>(object);
    int index;
    if(push_button)
    {
        QString object_name = push_button->objectName();
        index = object_name.toInt();
    }
    int id;
    id=sections[sectionnum].getPosts()[index];
    postnum=getPostsIndex(id);    //记录当前帖子索引
    //首先放帖子内容
    QString str;


    postwindow->setGeometry(50,150,500,200);
    s+="UserName:"+posts[postnum].getuserName();
    s+="\n\nContent:"+posts[postnum].getContents();
    s+="\n----------------------------";
    str=QString::fromStdString(s);
    qDebug()<<str<<"uuu"<<endl;
    postwindow->setText(str);
    postwindow->setVisible(true);
    postwindow->setAlignment(Qt::AlignTop);
    PostUp->setStyleSheet("background-color:red");


    postTime->setGeometry(50,50,500,100);
    s="Time:"+posts[postnum].getTime();
    str=QString::fromStdString(s);
    postTime->setText(str);
    postTime->setVisible(true);
    postTime->setAlignment(Qt::AlignTop);

    //下面放评论

    showComments(postnum);
    writeComment->setVisible(true);
    writeComment->clear();

    if(userkind!=0)
    button11->setVisible(true);

}

void MainWindow::showModeratorName()
{
    string s;
    s="moderator:";
    s+=sections[sectionnum].getModeratorName();

    QString str=QString::fromStdString(s);
    moderatorName->setText(str);
    moderatorName->setGeometry(500,200,200,50);
    moderatorName->setVisible(true);

    button10->setGeometry(850,200,50,50);
    if(userkind==0)
    button10->setVisible(true);
}

void MainWindow::showComments(int index)
{
    int i;
    string s;
    int newindex;

    hidecommentandpost();
    paint->setGeometry(0,0,1000,400+(posts[index].getComments().size())*210);//设置画布大小

    commentshow->setText("评论:");
    commentshow->setGeometry(50,400,1100,50);
    commentshow->setVisible(true);

    for(i=0;i<posts[index].getComments().size();i++)
    {
       QLabel*comment=new QLabel(paint);
       newindex=getCommentsIndex(posts[index].getComments()[i]);
       s=comments[newindex].getContents();
       s+="\n";
       s+="userName:";
       s+=comments[newindex].getuserName();
       s+="\n";
       s+="time:";
       s+=comments[newindex].getTime();
       s+="\n--------------------------------------";
       QString str=QString::fromStdString(s);
       comment->setText(str);
       commentbuttons.push_back(comment);
       commentbuttons[i]->setGeometry(50,400+210*i,1100,210);
       commentbuttons[i]->setVisible(true);

       QPushButton*CommentDelete=new QPushButton("删除",paint);
       QPushButton*CommentAccuse=new QPushButton("举报",paint);
       CommentDelete->setGeometry(0,450+210*(i),50,50);
       CommentAccuse->setGeometry(0,500+210*(i),50,50);

       if(userkind==2&&posts[postnum].getuserName()==moderators[num].getuserName()||
               userkind==1&&posts[postnum].getuserName()==ordinaryusers[num].getuserName())
       CommentDelete->setVisible(true);
       CommentAccuse->setVisible(true);
       commentAccuse.push_back(CommentAccuse);
       commentbuttonsDelete.push_back(CommentDelete);
       commentAccuse[i]->setObjectName(QString::number(i));
       commentbuttonsDelete[i]->setObjectName(QString::number(i));
       connect(commentbuttonsDelete[i], SIGNAL(clicked()), this, SLOT(ClickButton11()));
       connect(commentAccuse[i], SIGNAL(clicked()), this, SLOT(ClickButton15()));
    }
}



void MainWindow::hidecommentandpost()
{
    int i;
    for(i=0;i<postbuttons.size();i++)
    {
        postbuttonsDelete[i]->setVisible(false);
        postbuttons[i]->setVisible(false);
    }
    for(i=0;i<commentbuttons.size();i++)
    {
        commentbuttonsDelete[i]->setVisible(false);
        commentbuttons[i]->setVisible(false);
        commentAccuse[i]->setVisible(false);
    }
    postbuttons.clear();
    postbuttonsDelete.clear();
    commentbuttons.clear();
    commentbuttonsDelete.clear();
    commentAccuse.clear();
    commentshow->setVisible(false);
    PostTimeShow->setVisible(false);
    PostUp->setVisible(false);
}

void MainWindow::ClickButton7()   //增加底部的评论
{
    QString strText;
    strText = writeComment->toPlainText();
    if(strText!="")
    addcomments(strText);
    else
    {
        QLabel*text=new QLabel("输入不能为空");
        text->setVisible(true);
        text->setFixedSize(300,300);
    }
}


void MainWindow::ClickButton8()    //发布新的帖子
{
    QString strText,strTitle;
    strText = writePost->toPlainText();
    strTitle= titleinsert->text();
    if(strText!=""&&strTitle!="")
    addPosts(strText,strTitle);
    else
    {
        QLabel*text=new QLabel("输入不能为空");
        text->setVisible(true);
    }
}

void MainWindow::addPosts(QString content,QString title)
{
    string s1,s2,s3;
    int id;

    time_t t = time(0);
       char tmp[64];
       strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A ",localtime(&t) );
       string s4(tmp);
       id=posts[posts.size()-1].getID()+1;
    if(userkind==1)
    {
        s1=ordinaryusers[num].getuserName();
        ordinaryusers[num].addPosts(id);
    }
    else if(userkind==2)
    {
        s1=moderators[num].getuserName();
        moderators[num].addPosts(id);
    }
    sections[sectionnum].changeposts(id);
    s2=title.toStdString();

    s3=content.toStdString();
    Post p(s1,s2,s3,s4,id);
    posts.push_back(p);
    showPosts();
}
void MainWindow::showPosts()
{
    int i;
    int id;
    int index;
    hidecommentandpost();
    cout<<sections[sectionnum].getPosts().size()<<"yy"<<endl;
    for(i=0;i<sections[sectionnum].getPosts().size();i++)
    {
        QPushButton*p=new QPushButton(paint);
        id=sections[sectionnum].getPosts()[i];
        index=getPostsIndex(id);
        string s=posts[index].getTitle();
        QString str=QString::fromStdString(s);
        p->setText(str);
        p->setStyleSheet("QPushButton{text-align : top;}");
        postbuttons.push_back(p);
        postbuttons[i]->setGeometry(120,50*(i+1),1700,50);//  显示帖子
        postbuttons[i]->setVisible(true);

        QPushButton*q=new QPushButton("delete",paint);
        postbuttonsDelete.push_back(q);
        postbuttonsDelete[i]->setGeometry(0,50*(i+1),120,50);//  显示帖子删除按钮

        if(userkind==2&&moderators[num].getSection()==sectionnum||
                (userkind==1&&posts[index].getuserName()==ordinaryusers[num].getuserName()
                 &&posts[index].getComments().size()==0)
                ||(userkind==2&&posts[index].getuserName()==moderators[num].getuserName()
                   &&posts[index].getComments().size()==0))  //判断是否是版主，判断是否是当前用户的帖子
            postbuttonsDelete[i]->setVisible(true);
        else
            postbuttonsDelete[i]->setVisible(false);

        postbuttons[i]->setVisible(true);
    }

    for(i=0;i<postbuttons.size();i++)
    {
        postbuttons[i]->setObjectName(QString::number(i));
        postbuttonsDelete[i]->setObjectName(QString::number(i));
        connect(postbuttons[i], SIGNAL(clicked()), this, SLOT(ClickButton6()));
        connect(postbuttonsDelete[i], SIGNAL(clicked()), this, SLOT(ClickButton10()));
    }
    commentshow->setVisible(false);

}


void MainWindow::addcomments(QString str)    //增加评论
{
    string s1,s2;
    int id;

    time_t t = time(0);
       char tmp[64];
       strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A ",localtime(&t) );
       string s3(tmp);
       id=comments[comments.size()-1].getID()+1;
    if(userkind==1)
    {
        s1=ordinaryusers[num].getuserName();
        ordinaryusers[num].addComments(id);
    }
    else if(userkind==2)
    {
        s1=moderators[num].getuserName();
        moderators[num].addComments(id);
    }
    posts[postnum].changeComments(id);
    s2=str.toStdString();
    Comment c(s1,s2,s3,id);
    comments.push_back(c);
    showComments(postnum);
}


bool MainWindow::ifrepeat(string userName)
{
    int i;
    for(i=0;i<administrators.size();i++)
    {
        if(administrators[i].getuserName()==userName)
            return false;
    }
    for(i=0;i<ordinaryusers.size();i++)
    {
        if(administrators[i].getuserName()==userName)
            return false;
    }
    return true;
}


void MainWindow::produceNewUser(string a,string b)
{
    string c=ordinaryusers[ordinaryusers.size()-1].getId();
    int num = atoi(c.c_str());
    num++;
    c=to_string(num);
    Ordinaryuser o(c,a,b);
    ordinaryusers.push_back(o);
    ordinaryusers[ordinaryusers.size()-1].changeLevel(1);
    ordinaryusers[ordinaryusers.size()-1].addAccusationtimes(0);
}


void MainWindow::ClickButton3()   //注册状态
{

    QString nameUser = line1->text();
    QString password = line2->text();
    if(ifrepeat(nameUser.toStdString()))
    {
        QLabel*text=new QLabel("注册成功");  //弹出提示框注册成功
        text->setFixedSize(300,100);
        text->setVisible(true);
        produceNewUser(nameUser.toStdString(),password.toStdString());    //产生新用户
        userkind=1;
        num=ordinaryusers.size()-1;
        ordinaryusers[num].Online();
        startForum();
    }
}



int MainWindow::getPostsIndex(int id)
{
    int i;
    for(i=0;i<posts.size();i++)
        if(posts[i].getID()==id)
            return i;
}

int MainWindow::getCommentsIndex(int id)
{
    int i;
    for(i=0;i<comments.size();i++)
        if(comments[i].getID()==id)
            return i;
}

int MainWindow::ifconform(string userName,string password)   //判断当前用户是否存在并且密码是否正确,返回三种情况
{
    int i;
    if(!button4->isChecked())//不点击按钮，代表此时是普通用户输入
    {
        for(i=0;i<ordinaryusers.size();i++)
        {
            if(ordinaryusers[i].entryUser(userName,password)==1)
            {
                num=i;
                userkind=1;
                return 0;
            }
            else if(ordinaryusers[i].entryUser(userName,password)==2)
                return 2;
        }
        for(i=0;i<moderators.size();i++)
        {

            if(moderators[i].entryUser(userName,password)==1)
            {
                num=i;
                userkind=2;
                return 0;
            }
            else if(moderators[i].entryUser(userName,password)==2)
                return 2;
        }
    }
    else                         //点击按钮，代表此时是管理员输入
    {
        for(i=0;i<administrators.size();i++)
        {
            if(administrators[i].getuserName()==userName)
            {
                if(administrators[i].getpassword()==password)
                {
                    num=i;
                    userkind=0;
                    return 0;
                }
                else return 2;
            }
        }
    }
    return 1;
}

void MainWindow::ClickButton9()    //用户注销
{
    time_t t = time(0);
   char tmp[64];
   strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A ",localtime(&t) );
   string s3(tmp);
   if(userkind==0)
   {
       administrators[num].changeLastOnlineTime(s3);
       administrators[num].outUser();
   }
   else if(userkind==1)
   {
       ordinaryusers[num].changeLastOnlineTime(s3);
       ordinaryusers[num].outUser();
   }
   else if(userkind==2)
   {
       moderators[num].changeLastOnlineTime(s3);
       moderators[num].outUser();
   }
   userkind=-1;
   sectionnum=-1;
   postnum=-1;
    enterForum();
}


void MainWindow::ClickButton10()    //删除帖子操作
{
    QObject *object = QObject::sender();
    QPushButton *push_button = qobject_cast<QPushButton *>(object);
    int index;
    if(push_button)
    {
        QString object_name = push_button->objectName();
        index = object_name.toInt();
    }
    int id,i,j,k;
    id=sections[sectionnum].getPosts()[index];
    index=getPostsIndex(id);
    cout<<index<<"uuuuuuuuuuuuuu"<<endl;
    for(i=0;i<postbuttons.size();i++)
    {
        postbuttonsDelete[i]->setVisible(false);
        postbuttons[i]->setVisible(false);
    }

    //id=posts[index].getID();
    sections[sectionnum].deletePosts(id);   //删除板块下的帖子索引

    for(i=0;i<ordinaryusers.size();i++)    //删除对应的帖子
    {
        if(posts[index].getuserName()==ordinaryusers[i].getuserName())
        {
            ordinaryusers[i].deletePosts(id);
            for(j=0;j<posts[index].getComments().size();j++)
            {
                k=getCommentsIndex(posts[index].getComments()[j]);
                deleteUserComments(k);
                deleteComments(k);
            }
        }
    }
    for(i=0;i<moderators.size();i++)
    {
        if(posts[index].getuserName()==moderators[i].getuserName())
        {
            moderators[i].deletePosts(id);
            for(j=0;j<posts[index].getComments().size();j++)
            {
                //moderators[i].deleteComments(posts[index].getComments()[j]);
                k=getCommentsIndex(posts[index].getComments()[j]);
                deleteUserComments(k);
                deleteComments(k);
            }
        }
    }
    deletePosts(index); //删除帖子
    showPosts();
}

void MainWindow::deleteUserComments(int index)
{
    int i;
    for(i=0;i<ordinaryusers.size();i++)
    {
        if(ordinaryusers[i].getuserName()==comments[index].getuserName())
        {
            ordinaryusers[i].deleteComments(comments[index].getID());
        }
    }
    for(i=0;i<moderators.size();i++)
    {
        if(moderators[i].getuserName()==comments[index].getuserName())
        {
            moderators[i].deleteComments(comments[index].getID());
        }
    }
}

void MainWindow::ClickButton11()     //删除评论操作
{
    QObject *object = QObject::sender();
    QPushButton *push_button = qobject_cast<QPushButton *>(object);
    int index;
    if(push_button)
    {
        QString object_name = push_button->objectName();
        index = object_name.toInt();
    }
    int i,j,k,id;
    int newindex;
    id=posts[postnum].getComments()[index];
    newindex=getCommentsIndex(id);
    for(i=0;i<ordinaryusers.size();i++)
    {
        if(ordinaryusers[i].getuserName()==comments[newindex].getuserName())
        {
            ordinaryusers[i].deleteComments(id);
        }
    }
    for(i=0;i<moderators.size();i++)
    {
        if(moderators[i].getuserName()==comments[newindex].getuserName())
        {
            moderators[i].deleteComments(id);
        }
    }
    posts[postnum].deleteComments(id);
    showComments(postnum);

}

void MainWindow::deletePosts(int index)
{
    vector<class Post>::iterator it =posts.begin()+index;
    posts.erase(it);
}

void MainWindow::deleteComments(int index)
{
    vector<class Comment>::iterator it =comments.begin()+index;
    comments.erase(it);
}

void MainWindow::ClickButton12()
{
    //dia=new dialog();
    dialog->setVisible(true);
    linenewmoderator->setVisible(true);
    connect(chanemoderator, SIGNAL(clicked()), this, SLOT(ClickButton13()));
    linenewmoderator->setVisible(true);
}

void MainWindow::ClickButton13()
{
    QString str=linenewmoderator->text();
    string s=str.toStdString();
    changeModerator(s);
    showModeratorName();
    dialog->setVisible(false);
}

void MainWindow::changeModerator(string userName)    //改变版主
{
    sections[sectionnum].changeModerator(userName);
    int i,j;
    string s;
    vector<int>array;
    for(i=0;i<ordinaryusers.size();i++)
    {

        if(ordinaryusers[i].getuserName()==userName)
        {
            s=userName;
            ordinaryusers[i].changeuserName(moderators[sectionnum].getuserName());
            moderators[sectionnum].changeuserName(s);
            s=ordinaryusers[i].getpassword();
            ordinaryusers[i].changepassword(moderators[sectionnum].getpassword());
            moderators[sectionnum].changepassword(s);
            s=ordinaryusers[i].getId();
            ordinaryusers[i].changeID(moderators[sectionnum].getId());
            moderators[sectionnum].changeID(s);

            for(j=0;j<ordinaryusers[i].getCommentId().size();j++)
            {
                array.push_back(ordinaryusers[i].getCommentId()[j]);
            }
            ordinaryusers[i].changeComments(moderators[sectionnum].getCommentId());
            moderators[sectionnum].changeComments(array);

            for(j=0;j<ordinaryusers[i].getPostId().size();j++)
            {
                array.push_back(ordinaryusers[i].getPostId()[j]);
            }
            ordinaryusers[i].changePosts(moderators[sectionnum].getPostId());
            moderators[sectionnum].changePosts(array);

        }
    }
    sections[sectionnum].changeModerator(userName);
}


int  MainWindow::sumOnline()
{
    int i;
    int sum=0;
    for(i=0;i<ordinaryusers.size();i++)
    if(ordinaryusers[i].getOnline()==true)
            sum++;

    for(i=0;i<administrators.size();i++)
    if(administrators[i].getOnline()==true)
            sum++;

    for(i=0;i<moderators.size();i++)
    if(moderators[i].getOnline()==true)
            sum++;
    return sum;

}

void MainWindow::ClickButton14()   //显示用户详细信息
{
    string s,s1,s2,s3,s4,s5,s6,s7;
    int i;
    s="UserName:";
    if(userkind==1)
    {
    s+=ordinaryusers[num].getuserName();
    s1="ordinaryuser";
    s2=ordinaryusers[num].getId();
    i=ordinaryusers[num].getPostId().size();
    s3 = std::to_string(i);

    i=ordinaryusers[num].getCommentId().size();
    s4 = std::to_string(i);

    s5=ordinaryusers[num].getLastOnlineTime();

    i=ordinaryusers[num].getLevel();
    s6=std::to_string(i);
    //cout<<i<<"kkkkkkkkkk"<<endl;
    i=ordinaryusers[num].getAccusationtimes();
    s7=std::to_string(i);

    }
    else if(userkind==2)
    {
        s+=moderators[num].getuserName();
        s1="moderator";
        s2=moderators[num].getId();

        i=moderators[num].getPostId().size();
        s3 = std::to_string(i);

        i=moderators[num].getCommentId().size();
        s4 = std::to_string(i);

        s5=moderators[num].getLastOnlineTime();

        i=moderators[num].getLevel();
        s6=std::to_string(i);
        //cout<<i<<"kkkkkkkkkk"<<endl;
        i=moderators[num].getAccusationtimes();
        s7=std::to_string(i);
    }
    else if(userkind==0)
    {
    s+=administrators[num].getuserName();
    s1="administrator";
    s2=administrators[num].getId();
    }

    s+="\n\nuserkind:";
    s+=s1;
    s+="\n\nid:";
    s+=s2;
    if(userkind!=0)
    {
        s+="\n\n已发表帖子数目:"+s3+"\n\n已发表评论数目:"+s4+"\n\n最后一次登录时间:"+s5;
        s+="\n\n目前等级:"+s6;
        s+="\n\n被举报次数:"+s7;
    }

    s+="\n\n当前活跃人数:"+std::to_string(sumOnline());




    QString str=QString::fromStdString(s);
    QLabel*text=new QLabel(str);
    text->setFixedSize(700,800);
    text->setVisible(true);

}



void MainWindow::ClickButton15()
{

    //cout<<"yyyyyyyttttttt"<<endl;
    QObject *object = QObject::sender();
    QPushButton *push_button = qobject_cast<QPushButton *>(object);
    int index;
    if(push_button)
    {
        QString object_name = push_button->objectName();
        index = object_name.toInt();
    }
    int newindex;
    int i,id;
    id=posts[postnum].getComments()[index];
    newindex=getCommentsIndex(id);
    for(i=0;i<ordinaryusers.size();i++)
    {
        if(ordinaryusers[i].getuserName()==comments[newindex].getuserName())
        {

            ordinaryusers[i].addAccusationtimes(ordinaryusers[i].getAccusationtimes()+1);
        }
    }
    for(i=0;i<moderators.size();i++)
    {
        if(moderators[i].getuserName()==comments[newindex].getuserName())
        {
            moderators[i].addAccusationtimes(moderators[i].getAccusationtimes()+1);
        }
    }
    QLabel*text=new QLabel("举报成功");
    text->setVisible(true);
    text->setFixedSize(300,300);

}

MainWindow::~MainWindow()
{
    //delete ui;
}

