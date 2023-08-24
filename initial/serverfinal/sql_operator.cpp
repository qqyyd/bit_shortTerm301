#include<mysql/mysql.h>
#include<cstdio>
#include<string>
#include<vector>
#include <iostream>
using namespace std;

class PersonInfo {
        public:
        string name,usersMotto,image;
        PersonInfo(string _name = "-1faksjdfjsfaffjlka", string _usersMotto = "", string _image = ""):name(_name),usersMotto(_usersMotto),image(_image){}
    };
    class FriendRequest {
        public:
        PersonInfo from;
        string verifyText;
        FriendRequest(string _name = "-1ouyfou2ohgjlskdf", string _usersMotto = "", string _image = "", string _verifyText = ""):
        from(_name, _usersMotto, _image),verifyText(_verifyText){}
    };

class DatabaseManagement{
public:   
    MYSQL *con;
    string ip;
    string managerName;
    string managerPassword;
    string projectName;
    //ip地址， 管理员名称， 管理员密码， 数据库名称
    DatabaseManagement(string _ip, string _managerName, string _managerPassword, string _projectName){
        con = mysql_init(NULL);
        ip = _ip;
        managerName = _managerName;
        managerPassword = _managerPassword;
        projectName = _projectName;
        if(!mysql_real_connect(con,ip.c_str(),managerName.c_str(),managerPassword.c_str(),projectName.c_str(),0,NULL,CLIENT_MULTI_STATEMENTS)){
            fprintf(stderr,"can't connect database %s\n", mysql_error(con)); //除了这个cout
            exit(0);
        }
        else{
            fprintf(stderr,"connect success\n");
        }
    }
    
    //test success
    void save_message(string text, string from, string to){
        string search = "INSERT INTO CHAT_HISTORY VALUES(\"";
        search += from;
        search += "\",\"";
        search += to;
        search += "\",\"";
        search += text;
        search += "\");";
        mysql_query(con,search.c_str());
    }

    //test success
    int try_register(string id, string password){
        string search="SELECT * FROM USER WHERE NAME=\"";
        search += id;
        search += "\";";
        cout<<"sql语句:"<<search<<endl;
        auto search_res=mysql_query(con,search.c_str());
        auto result=mysql_store_result(con);
        int col=mysql_num_fields(result);//获取列数
        int row=mysql_num_rows(result);//获取行数
        if(search_res==0&&row!=0){ //
            return 1; //user exist;
        }
        search="INSERT INTO USER VALUES(\"";
        search+=id;
        search+="\",\"";
        search+=password;
        search+="\",\"\",\"\");";
        cout<<"sql语句:"<<search<<endl<<endl;
        mysql_query(con,search.c_str());

        mysql_free_result(result);
        return 0; //insert success;
    }

    //test success
    int try_login(string id,string password){
        string search="SELECT * FROM USER WHERE NAME=\"";
        search += id;
        search += "\";";
        cout<<"sql语句:"<<search<<endl;
        auto search_res=mysql_query(con,search.c_str());
        auto result=mysql_store_result(con);
        int col=mysql_num_fields(result);//获取列数
        int row=mysql_num_rows(result);//获取行数

        if(search_res==0&&row!=0){
            // cout<<"查询成功\n";
            auto info=mysql_fetch_row(result);//获取一行的信息
            // cout<<"查询到用户名:"<<info[0]<<" 密码:"<<info[1]<<endl;
            //密码正确
            if(info[1]==password){
                // cout<<"登录密码正确\n\n";

                return 0; // login success
            }
            //密码错误
            else{
                // cout<<"登录密码错误\n\n";
                
                return 1; // wrong password
            }
        }
        else{
            // cout<<"查询失败\n\n";

            return 2; // not such user
        }
    }
    //test success
    vector<PersonInfo> getFriendList(string id){
        vector<PersonInfo> vec;
        string search = "";
        search += "SELECT NAME,MOTTO,IMAGE_SRC FROM ";
        search +="((SELECT FRIEND_B FROM FRIENDSHIP WHERE FRIEND_A=\"";
        search += id;
        search += "\") as a ";
        search += "INNER JOIN USER ON a.FRIEND_B=USER.NAME);";
        cout << search << endl;
        auto search_res=mysql_query(con,search.c_str());
        auto result=mysql_store_result(con);
        int col=mysql_num_fields(result);//获取列数
        int row=mysql_num_rows(result);//获取行数
        auto info = mysql_fetch_row(result);
        while(info != NULL){
            vec.push_back(PersonInfo(info[0], info[1], info[2]));
            info = mysql_fetch_row(result);
        }

        mysql_free_result(result);
        return vec;
    }
    //test success
    bool check_friendship(string a, string b){
        string search = "";
        search += "SELECT * FROM FRIENDSHIP WHERE FRIEND_A=\"";
        search += a;
        search += "\" AND ";
        search += "FRIEND_B=\"";
        search += b;
        search += "\";";
        cout << search << endl;
        auto search_res=mysql_query(con,search.c_str());
        auto result=mysql_store_result(con);
        int col=mysql_num_fields(result);//获取列数
        int row=mysql_num_rows(result);//获取行数

        if(search_res==0&&row==0){ // 查询成功&&查询结果为空
            return false; //not friend
        }

        mysql_free_result(result);
        return true;
    }

    //test success
    PersonInfo find_person_by_id(string id){
        PersonInfo person;

        string search = "";
        search += "SELECT NAME,MOTTO,IMAGE_SRC FROM USER WHERE NAME=\"";
        search += id;
        search += "\";";
        cout << search << endl;
        auto search_res=mysql_query(con,search.c_str());
        auto result=mysql_store_result(con);
        int col=mysql_num_fields(result);//获取列数
        int row=mysql_num_rows(result);//获取行数

        auto info = mysql_fetch_row(result);
        while(info != NULL){
            person = PersonInfo(info[0], info[1], info[2]);
            info = mysql_fetch_row(result);
        }
        
        mysql_free_result(result);
        return person;
    }

    // test success
    void insert_friendship(string a, string b){
        string search = "";
        search += "INSERT INTO FRIENDSHIP VALUES (\"";
        search += a;
        search += "\",";
        search += "\"";
        search += b;
        search += "\");";
        cout << search << endl;
        mysql_query(con,search.c_str());
        search = "";
        search += "INSERT INTO FRIENDSHIP VALUES (\"";
        search += b;
        search += "\",";
        search += "\"";
        search += a;
        search += "\");";
        cout << search << endl;
        mysql_query(con,search.c_str());
    }
    // test success
    void change_head_image(string id, string imageSrc){
        string search = "";
        search += "UPDATE USER SET IMAGE_SRC=";
        search += "\"";
        search += imageSrc;
        search += "\" ";
        search += "WHERE NAME=\"";
        search += id;
        search += "\";";
        cout << search << endl;
        mysql_query(con,search.c_str());
        cout << "已经上传" << endl;
    }

    // test success
    void change_motto(string id, string motto){
        string search = "";
        search += "UPDATE USER SET MOTTO=";
        search += "\"";
        search += motto;
        search += "\" ";
        search += "WHERE NAME=\"";
        search += id;
        search += "\";";
        cout << search << endl;
        mysql_query(con,search.c_str());
    }

    // test success
    void save_friend_request(string verifyText, string from, string to){
        string search = "";
        search += "SELECT VERIFY_TEXT FROM FRIEND_REQUEST WHERE USER_A=\"";
        search += from;
        search += "\" AND USER_B=\"";
        search += to;
        search += "\";";
        cout << search << endl;
        auto search_res=mysql_query(con,search.c_str());
        auto result=mysql_store_result(con);
        int col=mysql_num_fields(result);//获取列数
        int row=mysql_num_rows(result);//获取行数

        if(search_res == 0 && row != 0){ // query success && not null
            search = "";
            search += "UPDATE FRIEND_REQUEST SET VERIFY_TEXT=\"";
            search += verifyText;
            search += "\" WHERE USER_A=\"";
            search += from;
            search += "\" AND USER_B=\"";
            search += to;
            search += "\";";
            cout << search << endl;
            mysql_query(con,search.c_str());
            return;
        }
        
        search = "";
        search += "INSERT INTO FRIEND_REQUEST VALUES(\"";
        search += from;
        search += "\",\"";
        search += to;
        search += "\",\"";
        search += verifyText;
        search += "\");";
        cout << search << endl;
        mysql_query(con,search.c_str());
    }
    // test success
    vector<FriendRequest> get_friend_request_list(string id){
        vector<FriendRequest> vec;

        string search = "";
        search += "SELECT NAME,MOTTO,IMAGE_SRC,VERIFY_TEXT FROM ";
        search +="((SELECT USER_A,VERIFY_TEXT FROM FRIEND_REQUEST WHERE USER_B=\"";
        search += id;
        search += "\") as a ";
        search += "INNER JOIN USER ON a.USER_A=USER.NAME);";
        cout << search << endl;
        auto search_res=mysql_query(con,search.c_str());
        auto result=mysql_store_result(con);
        int col=mysql_num_fields(result);//获取列数
        int row=mysql_num_rows(result);//获取行数
        auto info = mysql_fetch_row(result);
        while(info != NULL){
            vec.push_back(FriendRequest(info[0],info[1],info[2],info[3]));
            info = mysql_fetch_row(result);
        }

        mysql_free_result(result);
        return vec;
    }

    // test success;
    vector<string> getLatestMessage(string friend_a, string friend_b){
        vector<string> chat_history;
        int num = 20;

        string search = "";
        search += "SELECT * FROM CHAT_HISTORY WHERE (FRIEND_A=\"";
        search += friend_a;
        search += "\" AND FRIEND_B=\"";
        search += friend_b;
        search += "\") OR ";
        search += "(FRIEND_A=\"";
        search += friend_b;
        search += "\" AND FRIEND_B=\"";
        search += friend_a;
        search += "\");";
        cout << search << endl;
        auto search_res=mysql_query(con,search.c_str());
        auto result=mysql_store_result(con);
        int col=mysql_num_fields(result);//获取列数
        int row=mysql_num_rows(result);//获取行数
        auto info = mysql_fetch_row(result);

        while(info != NULL){
            if(col <= num){
                if(info[0] == friend_a && info[1] == friend_b){
                    chat_history.push_back(string("+") + string(info[2]));
                }
                else{
                    chat_history.push_back(string("-") + string(info[2]));
                }
            }
            col --;
            info = mysql_fetch_row(result);
        }
        
        mysql_free_result(result);
        return chat_history;
    }
    // test success
    void delete_friend_request(string from, string to){
        string search = "";
        search += "DELETE FROM FRIEND_REQUEST WHERE USER_A=\"";
        search += from;
        search += "\" AND ";
        search += "USER_B=\"";
        search += to;
        search += "\"";
        cout << search << endl;
        mysql_query(con,search.c_str());
    }

};
// create database bit2022_chatroom;
// use bit2022_chatroom;
// create table USER(NAME varchar(256) primary key, PASSWORD varchar(256) NOT NULL, MOTTO varchar(256), IMAGE_SRC varchar(10240));
// create table CHAT_HISTORY(FRIEND_A varchar(1024) NOT NULL, FRIEND_B varchar(1024) NOT NULL, TEXT varchar(1024));
// create table FRIENDSHIP(FRIEND_A varchar(1024) NOT NULL, FRIEND_B varchar(1024) NOT NULL);
// create table FRIEND_REQUEST(USER_A varchar(1024) NOT NULL, USER_B varchar(1024) NOT NULL, VERIFY_TEXT varchar(1024));


// DatabaseManagement sql_server("127.0.0.1","debian-sys-maint","jlThvcP2Wp44lLIk","ChatProject");

// int main(){
//     // fprintf(stderr, "%d\n", sql_server.try_register("123","2123123"));
//     // fprintf(stderr, "%d\n", sql_server.try_login("123","2123123"));
//     // sql_server.save_message("lisi","zhangsan","fasfs");
//     // PersonInfo person = sql_server.find_person_by_id("123");
//     // cout << person.name << person.usersMotto << person.image << endl;
//     // string id = "123";
//     // string password = "12233";
//     // string search="INSERT INTO USER VALUES(\"";
//     // search+=id;
//     // search+="\",\"";
//     // search+=password;
//     // search+="\");";
//     // cout << search << endl;
//     // mysql_query(sql_server.con,search.c_str());
//     // sql_server.insert_friendship("123","456");
//     // fprintf(stderr, "%d\n", sql_server.try_register("456","2123123"));
//     // vector<PersonInfo> vec = sql_server.getFriendList("123");
//     // cout << vec[0].name << vec[0].usersMotto << vec[0].image << endl;
//     // cout << sql_server.check_friendship("123","456") << endl;;
//     // SELECT NAME,MOTTO,IMAGE_SRC FROM (((SELECT FRIEND_B FROM FRIENDSHIP WHERE FRIEND_A="123") as a INNER JOIN USER ON a.FRIEND_B=USER.NAME));
//     // sql_server.change_head_image("123","3123");
//     // sql_server.change_motto("456","123321");
//     // vector<FriendRequest> vec;
//     // sql_server.save_friend_request("1233","123","456");
//     // vec = sql_server.get_friend_request_list("456");
//     // cout << vec[0].from.name << vec[0].verifyText << endl;
//     // vector<string> chat_history;
//     // chat_history = sql_server.getLatestMessage("zhangsan","fasfs");
//     // cout << chat_history[0] << endl;
//     // sql_server.save_friend_request("123333333","789","456");
//     return 0;
// }


