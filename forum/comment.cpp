#include "comment.h"
#include "header.h"
Comment::Comment(string a,string b,string c,int d)
{
    userName=a;
    content=b;
    time=c;
    id=d;
}

string Comment::getuserName()
{
    return userName;
}

string Comment::getContents()
{
    return content;
}


string Comment::getTime()
{
    return time;
}

int Comment::getID()
{
    return id;
}
