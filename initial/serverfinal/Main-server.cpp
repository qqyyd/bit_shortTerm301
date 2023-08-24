#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#include<vector>
#include<ctime>

#include<map>
#include<string>

#include<cassert>

#include"sql_operator.cpp"
using namespace std;


DatabaseManagement sql_server("127.0.0.1","qqyyd","123456","bit2023_chatroom");

class ThreadManagement{
    static const int MAXPHREAD = 100;
    pthread_t tid[MAXPHREAD];
    int totThread = 0;    

    vector<pthread_t *> pvector;
public:

    void init() {
        for (int i=0;i<MAXPHREAD;i++) pvector.push_back(&tid[i]);
    }

    pthread_t * get() {
        if (pvector.size()==0) throw "thread are all used";
        pthread_t *p = pvector.back();
        pvector.pop_back();
        return p;
    }

    void insert(unsigned int pval) {
        for (int i=0;i<MAXPHREAD;i++) {
            if (pval==(unsigned int)tid[i]) {
                pvector.push_back(&tid[i]);
                return;
            }
        }
        throw "pthread manage failed";
    }

    
}threadManagement;

map<string, int> id_to_confd;
string separator = "<#^&r|`{>";
string tend = "<`!#>";
int digitallen = 6;
int typelen = 2;

void writeit(int confd, const char* ch, int len) {
    char out[1000005]={0};
    sprintf(out,"%06d%s",len,ch);
    write(confd,out,len+6);
    fprintf(stderr,"%s\n",out);
}
void *threadFun(void *arg) {
    fprintf(stderr,"new connection!\n");
    int confd = *(int *)arg;
    char msg[1000006]={0};
    string current_idNumber = "";
    while (1) {


        memset(msg,0,sizeof(msg));
        fprintf(stderr,"ready:");
        if (recv(confd,msg,digitallen,0)==0) {
            puts("YEs");
            return 0;
        }
        printf("%s\n",msg);
        string readlen(msg);

        memset(msg,0,sizeof(msg));
        recv(confd,msg,typelen,0);
        string type(msg);

        string st_msg="";
        int needlen = atoi(readlen.c_str())-typelen;
        printf("%d\n",atoi(readlen.c_str()));
        // read(confd,msg,needlen);
        // st_msg+=string(msg);
        while (needlen) {
            memset(msg,0,sizeof(msg));
            if(recv(confd,msg,needlen,0)==0){
	    	    return 0;
	        }
            st_msg+=string(msg);
            needlen-=strlen(msg);
            printf("%d\n",needlen);
        } 
        // printf("---->%d\n",strlen(msg));
        printf("%d\n",st_msg.length());
        printf("%s\n",st_msg.c_str());
        // while (st_msg.find(tend)==st_msg.npos){
        //     memset(msg,0,sizeof(msg));
        //     recv(confd,msg,sizeof(msg),0);
        //     st_msg+=string(msg);
        //     // fprintf(stderr,"\n%s\n\n",st_msg.c_str());
        //     // printf("%d %d\n",st_msg.find(tend),st_msg.npos);
        // }
        // st_msg = st_msg.substr(0,st_msg.length()-tend.length());
        printf("%d\n",(int)st_msg.npos);
        fprintf(stderr,"\n%s\n\n",st_msg.c_str());
        // fprintf(stderr,"\n\n\n%c\n\n",st_msg[10]);
        if (type=="07") {
            string id = current_idNumber;
            string image = st_msg;
            sql_server.change_head_image(id,image);
            continue;
        }

        vector<string> msg_split;
        int lst = 0;
        while (st_msg.find(separator,lst)!=st_msg.npos) {
            int nxt = st_msg.find(separator,lst);
            msg_split.push_back(st_msg.substr(lst,nxt-lst));
            fprintf(stderr,"%d %d\n",lst,nxt);
            lst=nxt+separator.length();
            // fprintf(stderr,"\n\n\n\n\n%s\n\n\n\n\n",msg_split.back().c_str());
        }
        msg_split.push_back(st_msg.substr(lst,st_msg.npos-lst));
        if (type=="01") {//send message
            string text = msg_split[0];
            string from = msg_split[1];
            string to = msg_split[2];
            assert(from==current_idNumber);
            // assert(id_to_confd.count(to));

            sql_server.save_message(text,from,to);
            if (id_to_confd.count(to)) {
                string returnValue = "5";
                returnValue+=separator;
                returnValue+=from;
                returnValue+=separator;
                returnValue+=text;
                writeit(id_to_confd[to],returnValue.c_str(),returnValue.length());                
            }
            
            vector<PersonInfo> friendList = sql_server.getFriendList(current_idNumber);
            vector<pair<string,vector<string>>> msgList;
            for (auto afriend : friendList) {//type | numbertot | friend_id_1 | tot | 
                vector<string> msg_with_it = sql_server.getLatestMessage(current_idNumber,afriend.name);
                msgList.push_back({afriend.name,msg_with_it});
            }
            string returnValue = "4-2";
            returnValue+=separator;
            returnValue+=to_string(msgList.size());
            for (auto afriend : msgList) {
                returnValue+=separator;
                returnValue+=afriend.first;
                int len = afriend.second.size();
                returnValue+=separator;
                returnValue+=to_string(len);
                for (auto sentence : afriend.second) {
                    returnValue+=separator;
                    returnValue+=sentence;
                }
            }
            writeit(confd,returnValue.c_str(),returnValue.length());

        }
        if (type=="02") {//register
            fprintf(stderr,"try to register\n");
            string id = msg_split[0];
            string password = msg_split[1];
            int result = sql_server.try_register(id,password);//id, password
            if (result == 0) {
                string returnValue = "2";
                writeit(confd,returnValue.c_str(),returnValue.length());
                sql_server.insert_friendship(id,id);
            }else{
                string returnValue = "3";
                writeit(confd,returnValue.c_str(),returnValue.length());
            }
        }
        if (type=="03") {//login
            fprintf(stderr,"try to login\n");
            string id = msg_split[0];
            string password = msg_split[1];
            int result = sql_server.try_login(id,password);//id, password
            if (result == 0) {
                id_to_confd[id] = confd;
                current_idNumber = id;
                string returnValue = "0";
                writeit(confd,returnValue.c_str(),returnValue.length());
                sleep(1);
                vector<PersonInfo> friendList = sql_server.getFriendList(id);
                returnValue = "4";
                for (auto afriend : friendList) {
                    returnValue+=separator;
                    returnValue+=afriend.name;
                    returnValue+=separator;
                    returnValue+=afriend.usersMotto;
                    returnValue+=separator;
                    returnValue+=afriend.image;
                }
                writeit(confd,returnValue.c_str(),returnValue.length());
                sleep(1);

                vector<FriendRequest> requestList = sql_server.get_friend_request_list(id);
                returnValue = "4-3";
                for (auto aReq : requestList) {
                    returnValue+=separator;
                    returnValue+=aReq.from.name;
                    returnValue+=separator;
                    returnValue+=aReq.from.usersMotto;
                    returnValue+=separator;
                    returnValue+=aReq.from.image;
                    returnValue+=separator;
                    returnValue+=aReq.verifyText;
                }
                fprintf(stderr,"%s\n",returnValue.c_str());
                writeit(confd,returnValue.c_str(),returnValue.length());
                sleep(1);
                
                vector<pair<string,vector<string>>> msgList;
                for (auto afriend : friendList) {//type | numbertot | friend_id_1 | tot | 
                    vector<string> msg_with_it = sql_server.getLatestMessage(id,afriend.name);
                    msgList.push_back({afriend.name,msg_with_it});
                }
                returnValue = "4-2";
                returnValue+=separator;
                returnValue+=to_string(msgList.size());
                for (auto afriend : msgList) {
                    returnValue+=separator;
                    returnValue+=afriend.first;
                    int len = afriend.second.size();
                    returnValue+=separator;
                    returnValue+=to_string(len);
                    for (auto sentence : afriend.second) {
                        returnValue+=separator;
                        returnValue+=sentence;
                    }
                }
                writeit(confd,returnValue.c_str(),returnValue.length());
            
            }else{
                if (result==1) {
                    string returnValue = "1";
                    writeit(confd,returnValue.c_str(),returnValue.length());
                }else{
                    string returnValue = "1-2";
                    writeit(confd,returnValue.c_str(),returnValue.length());                   
                }

            }
        }
        if (type=="09") {
            string from = msg_split[0];
            string to = msg_split[1];

            PersonInfo person = sql_server.find_person_by_id(to);
            if (to!=person.name) {
                string returnValue = "6" + separator + "id_not_found";
                writeit(confd,returnValue.c_str(),returnValue.length());
            }else{
                if (sql_server.check_friendship(current_idNumber,to)==true) {
                    string returnValue = "6" + separator + "already_add";
                    writeit(confd,returnValue.c_str(),returnValue.length());
                }else{
                    string returnValue = "6" + separator + "success";
                    writeit(confd,returnValue.c_str(),returnValue.length());
                }
            }
        }
        if (type=="04") {//add friend
            string verifyText = msg_split[0];
            string from = msg_split[1];
            string to = msg_split[2];

            PersonInfo person = sql_server.find_person_by_id(from);
            if (id_to_confd.count(to)) {
                string returnValue = "";
                returnValue = "7";
                returnValue+=separator;
                returnValue+=person.name;
                returnValue+=separator;
                returnValue+=person.usersMotto;
                returnValue+=separator;
                returnValue+=person.image;
                returnValue+=separator;
                returnValue+=verifyText;
                writeit(id_to_confd[to],returnValue.c_str(),returnValue.length());                        
            }
            sql_server.save_friend_request(verifyText,from,to);

        }
        if (type=="06") {// reject friend request
            string thefriend = msg_split[0];
            string my = msg_split[1];

            string returnValue="9";
            returnValue+=separator;
            returnValue+=thefriend;
            writeit(id_to_confd[my],returnValue.c_str(),returnValue.length());

            sql_server.delete_friend_request(my,thefriend);
        }
        if (type=="05") {// accept friend request
            string thefriend = msg_split[0];
            string my = msg_split[1];

            sql_server.insert_friendship(thefriend,my);

            PersonInfo personmy = sql_server.find_person_by_id(my);
            PersonInfo personfr = sql_server.find_person_by_id(thefriend);

            
            string returnValue="8";
            returnValue+=separator;
            returnValue+=personfr.name;
            returnValue+=separator;
            returnValue+=personfr.usersMotto;
            returnValue+=separator;
            returnValue+=personfr.image;
            if (id_to_confd.count(my)) writeit(id_to_confd[my],returnValue.c_str(),returnValue.length());

            returnValue="8";
            returnValue+=separator;
            returnValue+=personmy.name;
            returnValue+=separator;
            returnValue+=personmy.usersMotto;
            returnValue+=separator;
            returnValue+=personmy.image;
            if (id_to_confd.count(thefriend)) writeit(id_to_confd[thefriend],returnValue.c_str(),returnValue.length());

            sql_server.delete_friend_request(my,thefriend);
        }   
        if (type=="08") {//change MOTTO
            string id = current_idNumber;
            string Motto = msg_split[0];
            sql_server.change_motto(id,Motto);
        }    
    }

    threadManagement.insert((unsigned int)pthread_self());
    return 0;
	// puts("client+1");
// 	int confd = *(int *)arg;
// 	static char buf[2005];
// 	while (1) {
// 		if (recv(confd,buf,sizeof(buf),0)==0) {
// 			return 0;
// 		} 
// 		printf("%s\n",buf);
// 		writeit(confd,buf,strlen(buf));
// 	}
}
int main()
{
	struct sockaddr_in my_addr;
	memset(&my_addr, 0, sizeof(my_addr));
	my_addr.sin_family = AF_INET; 
	my_addr.sin_port = htons(8889); 
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	int lisfd = socket(AF_INET,SOCK_STREAM,0);
	
	int bind_result = bind(lisfd, (struct sockaddr *)&my_addr, sizeof(my_addr));
	
	int listen_result = listen(lisfd, 20);
    threadManagement.init();
    static int confd[100005];
	while (1) {
        int x = rand()%100000;
		confd[x] = accept(lisfd,NULL,NULL);
		if (confd[x]==-1) return puts("!"),-1;
		pthread_create(threadManagement.get(),NULL,threadFun,&confd[x]);
        sleep(1);
	}
	
}
