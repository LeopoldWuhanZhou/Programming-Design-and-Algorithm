#include<iostream>
#include<iomanip>
#include<vector>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
int m,n,r,k,T,t;
int rednum=0,bluenum=0;
int soldierlife[5],soldierattack[5];
int redSeq[5]={2,3,4,1,0},blueSeq[5]={3,0,1,2,4};
class weapon
{
public:
    int id;
    int attack;
    char name[10];
    int use;
    weapon(int i,const char *s,int k):id(i),use(k){
        strcpy(name,s);
    };
    weapon(const weapon &c,int boss)
    {
        id=c.id;
        strcpy(name,c.name);
        use=c.use;
        if(id==0) attack=boss*2/10;
        else if(id==2) attack=r;
    }
};
weapon *weaponPool[3]={new weapon(0,"sword",-1),new weapon(1,"bomb",1),new weapon(2,"arrow",3)};
class soldier
{
public:
    int id;
    int num;
    int location;
    int elements;
    int attack;
    vector<weapon*> w;
    int weaponnum;
    int sword;
    int bomb;
    int arrow;
    char camp[10];
    char name[10];
    double energy;
    int shutup;
    soldier(){}
    soldier(int a,const char *s1,int b,const char *s2,int c,int d):id(a),num(b),elements(c),attack(d) 
    {
        location=0;
        weaponnum=0;
        sword=-1;
        bomb=-1;
        arrow=-1;
        strcpy(camp,s1);
        strcpy(name,s2);
        shutup=0;
    }
    virtual void loyaltyreport(){};
    void reportweapon()
    {
        if(elements<=0) return;
        bool flag=0;
        cout<<camp<<" "<<name<<" "<<num<<" has ";
        if((sword<0||w[sword]->attack==0)&&bomb<0&&arrow<0) cout<<"no weapon"<<endl;
        else
        {
            if(arrow>=0)
            {
                if(flag) cout<<",";
                cout<<"arrow("<<w[arrow]->use<<")";
                flag=1;
            }
            if(bomb>=0)
            {
                if(flag) cout<<",";
                cout<<"bomb";
                flag=1;
            }
            if(sword>=0&&w[sword]->attack>0)
            {
                if(flag) cout<<",";
                cout<<"sword("<<w[sword]->attack<<")";
                flag=1;
            }
            cout<<endl;
        }
    }
};
vector<soldier*> soldierpool;
class dragon:public soldier
{
public:
    dragon(const char *s,int n,int life,int attack):soldier(0,s,n,"dragon",life,attack)
    {
        w.push_back(new weapon(*weaponPool[n%3],attack));
        if(n%3==0) sword=0;
        else if(n%3==1) bomb=0;
        else arrow=0;
    }
};
class ninja:public soldier
{
public:
    ninja(const char *s,int n,int life,int attack):soldier(1,s,n,"ninja",life,attack) 
    {
        w.push_back(new weapon(*weaponPool[n%3],attack));
        w.push_back(new weapon(*weaponPool[(n+1)%3],attack));
        if(n%3==0) 
        {
            sword=0;
            bomb=1;
        }
        else if(n%3==1) 
        {
            bomb=0;
            arrow=1;
        }
        else 
        {
            arrow=0;
            sword=1;
        }
    }
};
class iceman:public soldier
{
public:
    int steps;
    iceman(const char *s,int n,int life,int attack):soldier(2,s,n,"iceman",life,attack) 
    {
        steps=0;
        w.push_back(new weapon(*weaponPool[n%3],attack));
        if(n%3==0) sword=0;
        else if(n%3==1) bomb=0;
        else arrow=0;
    }
};
class lion:public soldier
{
public:
    int loyalty;
    lion(const char *s,int n,int b,int life,int attack):soldier(3,s,n,"lion",life,attack),loyalty(b){}
    void loyaltyreport()override
    {
        cout<<"Its loyalty is "<<loyalty<<endl;
    }
};
class wolf:public soldier
{
public:
    wolf(const char *s,int n,int life,int attack):soldier(4,s,n,"wolf",life,attack){}
};
class HeadQuarter
{
public:
    char name[10];
    int id;
    int element;
    int seq[5];
    int pos;
    int num;
    soldier *list[100];
    HeadQuarter(){}
    HeadQuarter(int a,const char s[],int b,const int se[])
    {
        id=a;
        strcpy(name,s);
        element=b;
        for(int i=0;i<=4;i++)
            seq[i]=se[i];
        pos=0;
        num=0;
    }
    soldier *add(int i) 
    {
        switch(i)
        {
            case 0:
                list[num]=new dragon(name,num+1,soldierlife[i],soldierattack[i]);
                list[num]->energy=double(element)/soldierlife[i];
                break;
            case 1:
                list[num]=new ninja(name,num+1,soldierlife[i],soldierattack[i]);
                break;
            case 2:
                list[num]=new iceman(name,num+1,soldierlife[i],soldierattack[i]);
                break;
            case 3:
                list[num]=new lion(name,num+1,element,soldierlife[i],soldierattack[i]);
                break;
            case 4:
                list[num]=new wolf(name,num+1,soldierlife[i],soldierattack[i]);
                break;
        }
        soldierpool.push_back(list[num]);
        if(id==0) list[num]->location=0;
        else if(id==1) list[num]->location=n+1;
        num++;
        return list[num-1];
    }//add soldier
    void bornreport(soldier *c) 
    {
        cout<<setfill('0')<<setw(3)<<t/60<<":00 "<<name<<" "<<c->name<<" "<<c->num<<" born"<<endl;
        c->loyaltyreport();
        if(!strcmp("dragon",c->name)) 
        {
            cout<<"Its morale is "<<fixed<<setprecision(2)<<c->energy<<endl;
        }
    }
    friend void elementreport();
    void born()
    {
        if(pos>=5) pos-=5;
        if(element>=soldierlife[seq[pos]]) 
        {
            element-=soldierlife[seq[pos]];
            soldier *newsoldier=add(seq[pos]);
            bornreport(newsoldier);
            pos++;
        }
    }
    ~HeadQuarter()
    {
        for(int i=0;i<num;i++)
            list[i]=NULL;
        memset(list,0,sizeof(list));
    }//destructor
};
HeadQuarter red,blue;
class city
{
public:
    int flag;
    int elements;
    map<const char*,soldier*> player;
    int lastwinner,thiswinner,win;
    city() 
    {
		player["red"]=NULL;
		player["blue"]=NULL;
		flag=0;
		lastwinner=0;
        thiswinner=0;
		elements=0;
        win=0;
	}
    bool changeflag()
    {
        bool f=0;
        if(lastwinner!=0&&lastwinner==thiswinner) 
        {
            if(thiswinner!=flag)
            {
                f=1;
                if(thiswinner==1) cout<<setfill('0')<<setw(3)<<t/60<<":40 red flag raised in city ";
                if(thiswinner==-1) cout<<setfill('0')<<setw(3)<<t/60<<":40 blue flag raised in city ";
            }
            flag=thiswinner;
        }
        return f;
    }//based on the lastwinner and thiswinner, change the flag
};
city cityseq[50];
bool comparesoldier(const soldier *s1,const soldier *s2)
{
    if(s1->location!=s2->location) return s1->location<s2->location;
    return !strcmp(s1->camp,"red"); 
}
void refresh() 
{
    auto p=soldierpool.begin();
    for(;p!=soldierpool.end();p++) 
    {
        if((*p)->elements<=0) 
        {
            auto *t=*p;
            p=soldierpool.erase(p);
            t=NULL;
            if(p==soldierpool.end()) break;
        }
    }//clean dead soldiers
    sort(soldierpool.begin(),soldierpool.end(),comparesoldier);
    for(int i=1;i<=n;i++)
    {
        if(cityseq[i].player["red"]!=NULL)
        {
            if(cityseq[i].player["red"]->elements<=0) cityseq[i].player["red"]=NULL;
        }
        if(cityseq[i].player["blue"]!=NULL)
        {
            if(cityseq[i].player["blue"]->elements<=0) cityseq[i].player["blue"]=NULL;
        }
    }
}//refresh the soldierpool and all the states
void escape()
{
    auto p=soldierpool.begin();
    for (;p!=soldierpool.end();p++)
    {
        if((*p)->id==3&&(*p)->elements>0)
        {
            lion *l=dynamic_cast<lion*>(*p);
            if(l->loyalty<=0) 
            {
                cout<<setfill('0')<<setw(3)<<t/60<<":05 "<<l->camp<<" "<<l->name<<" "<<l->num<<" ran away"<<endl;
                l->elements=0;
            }
        }
    }
}
bool march()
{
    int flag=0,shutupr=1,shutupb=1; 
    auto p=soldierpool.begin();
    //move
    for(;p!=soldierpool.end();p++) 
    {
        soldier *s=*p;
        if(s->elements<=0) continue;
        if(!strcmp(s->camp,"red")) 
        {
            if(s->location<n+1) s->location++;
        }
        else if(!strcmp(s->camp,"blue")) 
        {
            if(s->location>0) s->location--;
        }
        if(!strcmp(s->camp,"red")) 
        {
            cityseq[s->location].player["red"]=s;
            if(cityseq[s->location-1].player["red"]!=NULL&&cityseq[s->location-1].player["red"]->name==cityseq[s->location].player["red"]->name) cityseq[s->location-1].player["red"]=NULL;
        }
        if(!strcmp(s->camp,"blue")) 
        {
            cityseq[s->location].player["blue"]=s;
            if(cityseq[s->location+1].player["blue"]!=NULL&&cityseq[s->location+1].player["blue"]->name==cityseq[s->location].player["blue"]->name) cityseq[s->location+1].player["blue"]=NULL;
        }
    }
    refresh();
    //after move
    for(p=soldierpool.begin();p!=soldierpool.end();p++)
    {
        soldier *s=*p;
        if(s->shutup==0) cout<<setfill('0')<<setw(3)<<t/60<<":10 "<<s->camp<<" "<<s->name<<" "<<s->num;
        if(s->id==2) 
        {
            iceman *ice=dynamic_cast<iceman *>(s);
            ice->steps++;
            if(ice->steps%2==0)
            {
                ice->attack+=20;
                if(ice->elements>9) ice->elements-=9;
                else ice->elements=1;
            }
        }
        if(s->location==0&&s->shutup==0)
        {
            s->shutup=1;
            cout<<" reached red headquarter";
            cout<<" with "<<s->elements<<" elements and force "<<s->attack<<endl;
            rednum++;
        } 
        else if(s->location==n+1&&s->shutup==0)
        {
            s->shutup=1;
            cout<<" reached blue headquarter";
            cout<<" with "<<s->elements<<" elements and force "<<s->attack<<endl;
            bluenum++;
        } 
        else if(1<=s->location&&s->location<=n)
        {
            cout<<" marched to city "<<s->location;
            cout<<" with "<<s->elements<<" elements and force "<<s->attack<<endl;
        }
        if(rednum==2&&shutupr) 
        {
            shutupr=0;
            cout<<setfill('0')<<setw(3)<<t/60<< ":10 "<<"red headquarter was taken"<<endl;
            flag=1;
        }
        else if(bluenum==2&&shutupb) 
        {
            shutupb=0;
            cout<<setfill('0')<<setw(3)<<t/60<< ":10 "<<"blue headquarter was taken"<<endl;
            flag=1;
        }
    }
    refresh();
    return flag!=0;//finish the game or not
}
void elementreport() 
{
    cout<<setfill('0')<<setw(3)<<t/60<<":50 ";
    cout<<red.element<<" elements in "<<red.name<<" headquarter"<<endl;
    cout<<setfill('0')<<setw(3)<<t/60<<":50 "<<blue.element<<" elements in "<<blue.name<<" headquarter"<<endl;
}
void soldierreport()
{
    auto p=soldierpool.begin();
    for(;p!=soldierpool.end();p++) 
    {
        if((*p)->elements<=0) continue;
        cout<<setfill('0')<<setw(3)<<t/60<<":55 ";
        (*p)->reportweapon();
    }
}
void shot()
{
    for(int i=1;i<=n;i++)
    {
        if(cityseq[i].player["red"]!=NULL&&i<=n-1)
        {
            if(cityseq[i].player["red"]->arrow>=0&&cityseq[i+1].player["blue"]!=NULL)
            {
                cityseq[i+1].player["blue"]->elements-=r;
                cityseq[i].player["red"]->w[cityseq[i].player["red"]->arrow]->use--;
                if(cityseq[i].player["red"]->w[cityseq[i].player["red"]->arrow]->use<=0) cityseq[i].player["red"]->arrow=-1;
                cout<<setfill('0')<<setw(3)<<t/60<< ":35 red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" shot";
                if(cityseq[i+1].player["blue"]->elements<=0) cout<<" and killed blue "<<cityseq[i+1].player["blue"]->name<<" "<<cityseq[i+1].player["blue"]->num;
                cout<<endl;
            }
        }
        if(cityseq[i].player["blue"]!=NULL&&i>=2)
        {
            if(cityseq[i].player["blue"]->arrow>=0&&cityseq[i-1].player["red"]!=NULL)
            {
                cityseq[i-1].player["red"]->elements-=r;
                cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->arrow]->use--;
                if(cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->arrow]->use<=0) cityseq[i].player["blue"]->arrow=-1;
                cout<<setfill('0')<<setw(3)<<t/60<< ":35 blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" shot";
                if(cityseq[i-1].player["red"]->elements<=0) cout<<" and killed red "<<cityseq[i-1].player["red"]->name<<" "<<cityseq[i-1].player["red"]->num;
                cout<<endl;
            }
        }
    }
}
void usebomb()
{
    for(int i=1;i<=n;i++)
    {
        if(cityseq[i].player["red"]!=NULL&&cityseq[i].player["blue"]!=NULL)
        {
            if(cityseq[i].flag==1||(cityseq[i].flag==0&&i%2==1))//red first
            {
                int temp1=cityseq[i].player["blue"]->elements;
                temp1-=cityseq[i].player["red"]->attack;
                if(cityseq[i].player["red"]->sword>=0) temp1-=cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack;
                if(cityseq[i].player["blue"]->bomb>=0&&cityseq[i].player["red"]->elements>0&&cityseq[i].player["blue"]->elements>0)
                {
                    if(temp1<=0) 
                    {
                        cout<<setfill('0')<<setw(3)<<t/60<<":38 blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" used a bomb and killed red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<endl;
                        cityseq[i].player["blue"]->elements=-10;
                        cityseq[i].player["red"]->elements=-10;
                        cityseq[i].player["blue"]=NULL;
                        cityseq[i].player["red"]=NULL;
                        continue;
                    }
                }
                if(cityseq[i].player["red"]->bomb>=0&&cityseq[i].player["red"]->elements>0&&temp1>0&&cityseq[i].player["blue"]->id!=1)
                {
                    int temp=cityseq[i].player["red"]->elements;
                    temp-=cityseq[i].player["blue"]->attack/2;
                    if(cityseq[i].player["blue"]->sword>=0) temp-=cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack;
                    if(temp<=0) 
                    {
                        cout<<setfill('0')<<setw(3)<<t/60<<":38 red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" used a bomb and killed blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<endl;
                        cityseq[i].player["blue"]->elements=-10;
                        cityseq[i].player["red"]->elements=-10;
                        cityseq[i].player["blue"]=NULL;
                        cityseq[i].player["red"]=NULL;
                    }
                }
            }
            else
            {
                int temp1=cityseq[i].player["red"]->elements;
                temp1-=cityseq[i].player["blue"]->attack;
                if(cityseq[i].player["blue"]->sword>=0) temp1-=cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack;
                if(cityseq[i].player["red"]->bomb>=0&&cityseq[i].player["red"]->elements>0&&cityseq[i].player["blue"]->elements>0)
                {
                    if(temp1<=0) 
                    {
                        cout<<setfill('0')<<setw(3)<<t/60<<":38 red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" used a bomb and killed blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<endl;
                        cityseq[i].player["blue"]->elements=-10;
                        cityseq[i].player["red"]->elements=-10;
                        cityseq[i].player["blue"]=NULL;
                        cityseq[i].player["red"]=NULL;
                        continue;
                    }
                }
                if(cityseq[i].player["blue"]->bomb>=0&&temp1>0&&cityseq[i].player["blue"]->elements>0&&cityseq[i].player["red"]->id!=1)
                {
                    int temp=cityseq[i].player["blue"]->elements;
                    temp-=cityseq[i].player["red"]->attack/2;
                    if(cityseq[i].player["red"]->sword>=0) temp-=cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack;
                    if(temp<=0) 
                    {
                        cout<<setfill('0')<<setw(3)<<t/60<<":38 blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" used a bomb and killed red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<endl;
                        cityseq[i].player["blue"]->elements=-10;
                        cityseq[i].player["red"]->elements=-10;
                        cityseq[i].player["blue"]=NULL;
                        cityseq[i].player["red"]=NULL;
                    }
                }
            }
        }
    }
}
void battle()
{
    for(int i=1;i<=n;i++)
    {
        if(cityseq[i].player["red"]!=NULL&&cityseq[i].player["blue"]!=NULL)
        {
            if(cityseq[i].player["red"]->elements<=0&&cityseq[i].player["blue"]->elements<=0)
            {
                cityseq[i].player["red"]=NULL;
                cityseq[i].player["blue"]=NULL;
                continue;
            }
            if((cityseq[i].player["red"]->elements>0&&cityseq[i].player["blue"]->elements<=0)||(cityseq[i].player["blue"]->elements>0&&cityseq[i].player["red"]->elements<=0))
            {
                cityseq[i].lastwinner=cityseq[i].thiswinner;
                if(cityseq[i].player["red"]->elements>0) 
                {
                    if(cityseq[i].player["red"]->id==4)
                    {
                        if(cityseq[i].player["red"]->sword<0&&cityseq[i].player["blue"]->sword>=0)
                        {
                            cityseq[i].player["red"]->sword=max(cityseq[i].player["red"]->bomb,cityseq[i].player["red"]->arrow)+1;
                            cityseq[i].player["red"]->w.push_back(new weapon(*weaponPool[0],cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack));
                            cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack=cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack;
                        }
                        if(cityseq[i].player["red"]->bomb<0&&cityseq[i].player["blue"]->bomb>=0)
                        {
                            cityseq[i].player["red"]->bomb=max(cityseq[i].player["red"]->sword,cityseq[i].player["red"]->arrow)+1;
                            cityseq[i].player["red"]->w.push_back(new weapon(*weaponPool[1],r));
                        }
                        if(cityseq[i].player["red"]->arrow<0&&cityseq[i].player["blue"]->arrow>=0)
                        {
                            cityseq[i].player["red"]->arrow=max(cityseq[i].player["red"]->sword,cityseq[i].player["red"]->bomb)+1;
                            cityseq[i].player["red"]->w.push_back(new weapon(*weaponPool[2],r));
                            cityseq[i].player["red"]->w[cityseq[i].player["red"]->arrow]->use=cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->arrow]->use;
                        }
                    }
                    if((cityseq[i].flag==1||(cityseq[i].flag==0&&i%2==1))&&(cityseq[i].player["red"]->id==0))//yell
                    {
                        cityseq[i].player["red"]->energy+=0.2;
                        if(cityseq[i].player["red"]->energy>0.8) cout<<setfill('0')<<setw(3)<<t/60<< ":40 red"<<" "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" yelled in city "<<i<<endl;
                    }
                    cityseq[i].thiswinner=1;
                    cityseq[i].win=1;
                    cout<<setfill('0')<<setw(3)<<t/60<< ":40 red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" earned "<<cityseq[i].elements<<" elements for his headquarter"<<endl;
                    red.element+=cityseq[i].elements;
                    cityseq[i].elements=0;
                    cityseq[i].player["blue"]=NULL;
                }
                else 
                {
                    if(cityseq[i].player["blue"]->id==4)
                    {
                        if(cityseq[i].player["blue"]->sword<0&&cityseq[i].player["red"]->sword>=0)
                        {
                            cityseq[i].player["blue"]->sword=max(cityseq[i].player["blue"]->bomb,cityseq[i].player["blue"]->arrow)+1;
                            cityseq[i].player["blue"]->w.push_back(new weapon(*weaponPool[0],cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack));
                            cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack=cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack;
                        }
                        if(cityseq[i].player["blue"]->bomb<0&&cityseq[i].player["red"]->bomb>=0)
                        {
                            cityseq[i].player["blue"]->bomb=max(cityseq[i].player["blue"]->sword,cityseq[i].player["blue"]->arrow)+1;
                            cityseq[i].player["blue"]->w.push_back(new weapon(*weaponPool[1],r));
                        }
                        if(cityseq[i].player["blue"]->arrow<0&&cityseq[i].player["blue"]->arrow>=0)
                        {
                            cityseq[i].player["blue"]->arrow=max(cityseq[i].player["blue"]->sword,cityseq[i].player["blue"]->bomb)+1;
                            cityseq[i].player["blue"]->w.push_back(new weapon(*weaponPool[2],r));
                            cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->arrow]->use=cityseq[i].player["red"]->w[cityseq[i].player["red"]->arrow]->use;
                        }
                    }
                    if((cityseq[i].flag==-1||(cityseq[i].flag==0&&i%2==0))&&(cityseq[i].player["blue"]->id==0))//yell
                    {
                        cityseq[i].player["blue"]->energy+=0.2;
                        if(cityseq[i].player["blue"]->energy>0.8) cout<<setfill('0')<<setw(3)<<t/60<< ":40 blue"<<" "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" yelled in city "<<i<<endl;
                    }
                    cityseq[i].thiswinner=-1;
                    cityseq[i].win=-1;
                    cout<<setfill('0')<<setw(3)<<t/60<< ":40 blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" earned "<<cityseq[i].elements<<" elements for his headquarter"<<endl;
                    blue.element+=cityseq[i].elements;
                    cityseq[i].elements=0;
                    cityseq[i].player["red"]=NULL;
                }
            }
            if(cityseq[i].changeflag()) cout<<i<<endl;
        }
        int templifer,templifeb;
        if(cityseq[i].player["red"]!=NULL&&cityseq[i].player["blue"]!=NULL)
        {
            if(cityseq[i].player["blue"]->id==3) templifeb=cityseq[i].player["blue"]->elements;
            if(cityseq[i].player["red"]->id==3) templifer=cityseq[i].player["red"]->elements;
            if(cityseq[i].flag==1||(cityseq[i].flag==0&&i%2==1))//red first
            {
                cout<<setfill('0')<<setw(3)<<t/60<<":40 red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" attacked blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" in city "<<i<<" with "<<cityseq[i].player["red"]->elements<<" elements and force "<<cityseq[i].player["red"]->attack<<endl;
                cityseq[i].player["blue"]->elements-=cityseq[i].player["red"]->attack;
                if(cityseq[i].player["red"]->sword>=0) 
                {
                    cityseq[i].player["blue"]->elements-=cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack;
                    cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack=cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack*8/10;
                    if(cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack==0) cityseq[i].player["red"]->sword=-1;
                }
                if(cityseq[i].player["blue"]->elements>0)//blue survive
                {
                    if(cityseq[i].player["blue"]->id!=1)//not ninja
                    {
                        cout<<setfill('0')<<setw(3)<<t/60<< ":40 blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" fought back against red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" in city "<<i<<endl;
                        cityseq[i].player["red"]->elements-=cityseq[i].player["blue"]->attack/2;
                        if(cityseq[i].player["blue"]->sword>=0) 
                        {
                            cityseq[i].player["red"]->elements-=cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack;
                            cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack=cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack*8/10;
                            if(cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack==0) cityseq[i].player["blue"]->sword=-1;//examine the sword
                        }
                    }
                    if(cityseq[i].player["red"]->elements<=0)
                    {
                        if(cityseq[i].player["red"]->id==3) cityseq[i].player["blue"]->elements+=templifer;
                        cityseq[i].win=-1;
                        cout<<setfill('0')<<setw(3)<<t/60<< ":40 red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" was killed in city "<<i<<endl;
                        cout<<setfill('0')<<setw(3)<<t/60<< ":40 blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" earned "<<cityseq[i].elements<<" elements for his headquarter"<<endl;
                        blue.element+=cityseq[i].elements;
                        cityseq[i].elements=0;
                        if(cityseq[i].player["blue"]->id==4)//wolf
                        {
                            if(cityseq[i].player["blue"]->sword<0&&cityseq[i].player["red"]->sword>=0)
                            {
                                cityseq[i].player["blue"]->sword=max(cityseq[i].player["blue"]->bomb,cityseq[i].player["blue"]->arrow)+1;
                                cityseq[i].player["blue"]->w.push_back(new weapon(*weaponPool[0],cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack));
                                cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack=cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack;
                            }
                            if(cityseq[i].player["blue"]->bomb<0&&cityseq[i].player["red"]->bomb>=0)
                            {
                                cityseq[i].player["blue"]->bomb=max(cityseq[i].player["blue"]->sword,cityseq[i].player["blue"]->arrow)+1;
                                cityseq[i].player["blue"]->w.push_back(new weapon(*weaponPool[1],r));
                            }
                            if(cityseq[i].player["blue"]->arrow<0&&cityseq[i].player["blue"]->arrow>=0)
                            {
                                cityseq[i].player["blue"]->arrow=max(cityseq[i].player["blue"]->sword,cityseq[i].player["blue"]->bomb)+1;
                                cityseq[i].player["blue"]->w.push_back(new weapon(*weaponPool[2],r));
                                cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->arrow]->use=cityseq[i].player["red"]->w[cityseq[i].player["red"]->arrow]->use;
                            }
                        }
                        cityseq[i].lastwinner=cityseq[i].thiswinner;
                        cityseq[i].thiswinner=-1;
                    }
                    else
                    {
                        if(cityseq[i].player["red"]->id==3)//loyalty 
                        {
                            lion *l=dynamic_cast<lion*>(cityseq[i].player["red"]);
                            l->loyalty-=k;
                        }
                        if(cityseq[i].player["blue"]->id==3)//loyalty 
                        {
                            lion *l=dynamic_cast<lion*>(cityseq[i].player["blue"]);
                            l->loyalty-=k;
                        }
                        if(cityseq[i].player["red"]->id==0)//yell
                        {
                            cityseq[i].player["red"]->energy-=0.2;
                            if(cityseq[i].player["red"]->energy>0.8) cout<<setfill('0')<<setw(3)<<t/60<< ":40 red"<<" "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" yelled in city "<<i<<endl;
                        }
                        cityseq[i].lastwinner=cityseq[i].thiswinner;
                        cityseq[i].thiswinner=0;
                    }
                }
                else
                {
                    cityseq[i].win=1;
                    cout<<setfill('0')<<setw(3)<<t/60<< ":40 blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" was killed in city "<<i<<endl;
                    if(cityseq[i].player["red"]->id==0)//yell
                    {
                        cityseq[i].player["red"]->energy+=0.2;
                        if(cityseq[i].player["red"]->energy>0.8) cout<<setfill('0')<<setw(3)<<t/60<< ":40 red"<<" "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" yelled in city "<<i<<endl;
                    }
                    cout<<setfill('0')<<setw(3)<<t/60<< ":40 red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" earned "<<cityseq[i].elements<<" elements for his headquarter"<<endl;
                    red.element+=cityseq[i].elements;
                    cityseq[i].elements=0;
                    if(cityseq[i].player["blue"]->id==3) cityseq[i].player["red"]->elements+=templifeb;
                    if(cityseq[i].player["red"]->id==4)//wolf
                    {
                        if(cityseq[i].player["red"]->sword<0&&cityseq[i].player["blue"]->sword>=0)
                        {
                            cityseq[i].player["red"]->sword=max(cityseq[i].player["red"]->bomb,cityseq[i].player["red"]->arrow)+1;
                            cityseq[i].player["red"]->w.push_back(new weapon(*weaponPool[0],cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack));
                            cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack=cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack;
                        }
                        if(cityseq[i].player["red"]->bomb<0&&cityseq[i].player["blue"]->bomb>=0)
                        {
                            cityseq[i].player["red"]->bomb=max(cityseq[i].player["red"]->sword,cityseq[i].player["red"]->arrow)+1;
                            cityseq[i].player["red"]->w.push_back(new weapon(*weaponPool[1],r));
                        }
                        if(cityseq[i].player["red"]->arrow<0&&cityseq[i].player["blue"]->arrow>=0)
                        {
                            cityseq[i].player["red"]->arrow=max(cityseq[i].player["red"]->sword,cityseq[i].player["red"]->bomb)+1;
                            cityseq[i].player["red"]->w.push_back(new weapon(*weaponPool[2],r));
                            cityseq[i].player["red"]->w[cityseq[i].player["red"]->arrow]->use=cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->arrow]->use;
                        }
                    }
                    cityseq[i].lastwinner=cityseq[i].thiswinner;
                    cityseq[i].thiswinner=1;
                }
            }
            else//blue first
            {
                cout<<setfill('0')<<setw(3)<<t/60<<":40 blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" attacked red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" in city "<<i<<" with "<<cityseq[i].player["blue"]->elements<<" elements and force "<<cityseq[i].player["blue"]->attack<<endl;
                cityseq[i].player["red"]->elements-=cityseq[i].player["blue"]->attack;
                if(cityseq[i].player["blue"]->sword>=0) 
                {
                    cityseq[i].player["red"]->elements-=cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack;
                    cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack=cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack*8/10;
                    if(cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack==0) cityseq[i].player["blue"]->sword=-1;
                }
                if(cityseq[i].player["red"]->elements>0)
                {
                    if(cityseq[i].player["red"]->id!=1)
                    {
                        cout<<setfill('0')<<setw(3)<<t/60<< ":40 red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" fought back against blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" in city "<<i<<endl;
                        cityseq[i].player["blue"]->elements-=cityseq[i].player["red"]->attack/2;
                        if(cityseq[i].player["red"]->sword>=0) 
                        {
                            cityseq[i].player["blue"]->elements-=cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack;
                            cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack=cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack*8/10;
                            if(cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack==0) cityseq[i].player["red"]->sword=-1;
                        }
                    }
                    if(cityseq[i].player["blue"]->elements<=0)
                    {
                        cityseq[i].win=1;
                        if(cityseq[i].player["blue"]->id==3) cityseq[i].player["red"]->elements+=templifeb;
                        cout<<setfill('0')<<setw(3)<<t/60<< ":40 blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" was killed in city "<<i<<endl;
                        cout<<setfill('0')<<setw(3)<<t/60<< ":40 red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" earned "<<cityseq[i].elements<<" elements for his headquarter"<<endl;
                        red.element+=cityseq[i].elements;
                        cityseq[i].elements=0;
                        if(cityseq[i].player["red"]->id==4)//wolf
                        {
                            if(cityseq[i].player["red"]->sword<0&&cityseq[i].player["blue"]->sword>=0)
                            {
                                cityseq[i].player["red"]->sword=max(cityseq[i].player["red"]->bomb,cityseq[i].player["red"]->arrow)+1;
                                cityseq[i].player["red"]->w.push_back(new weapon(*weaponPool[0],cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack));
                                cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack=cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack;
                            }
                            if(cityseq[i].player["red"]->bomb<0&&cityseq[i].player["blue"]->bomb>=0)
                            {
                                cityseq[i].player["red"]->bomb=max(cityseq[i].player["red"]->sword,cityseq[i].player["red"]->arrow)+1;
                                cityseq[i].player["red"]->w.push_back(new weapon(*weaponPool[1],r));
                            }
                            if(cityseq[i].player["red"]->arrow<0&&cityseq[i].player["blue"]->arrow>=0)
                            {
                                cityseq[i].player["red"]->arrow=max(cityseq[i].player["red"]->sword,cityseq[i].player["red"]->bomb)+1;
                                cityseq[i].player["red"]->w.push_back(new weapon(*weaponPool[2],r));
                                cityseq[i].player["red"]->w[cityseq[i].player["red"]->arrow]->use=cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->arrow]->use;
                            }
                        }
                        cityseq[i].lastwinner=cityseq[i].thiswinner;
                        cityseq[i].thiswinner=1;
                    }
                    else
                    {
                        if(cityseq[i].player["red"]->id==3)//loyalty 
                        {
                            lion *l=dynamic_cast<lion*>(cityseq[i].player["red"]);
                            l->loyalty-=k;
                        }
                        if(cityseq[i].player["blue"]->id==3)//loyalty 
                        {
                            lion *l=dynamic_cast<lion*>(cityseq[i].player["blue"]);
                            l->loyalty-=k;
                        }
                        if(cityseq[i].player["blue"]->id==0)//yell
                        {
                            cityseq[i].player["blue"]->energy-=0.2;
                            if(cityseq[i].player["blue"]->energy>0.8) cout<<setfill('0')<<setw(3)<<t/60<< ":40 blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" yelled in city "<<i<<endl;
                        }
                        cityseq[i].lastwinner=cityseq[i].thiswinner;
                        cityseq[i].thiswinner=0;
                    }
                }
                else
                {
                    if(cityseq[i].player["red"]->id==3) cityseq[i].player["blue"]->elements+=templifer;
                    cityseq[i].win=-1;
                    cout<<setfill('0')<<setw(3)<<t/60<< ":40 red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" was killed in city "<<i<<endl;
                    if(cityseq[i].player["blue"]->id==0)//yell
                    {
                        cityseq[i].player["blue"]->energy+=0.2;
                        if(cityseq[i].player["blue"]->energy>0.8) cout<<setfill('0')<<setw(3)<<t/60<< ":40 blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" yelled in city "<<i<<endl;
                    }
                    cout<<setfill('0')<<setw(3)<<t/60<< ":40 blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" earned "<<cityseq[i].elements<<" elements for his headquarter"<<endl;
                    blue.element+=cityseq[i].elements;
                    cityseq[i].elements=0;
                    if(cityseq[i].player["blue"]->id==4)//wolf
                    {
                        if(cityseq[i].player["blue"]->sword<0&&cityseq[i].player["red"]->sword>=0)
                        {
                            cityseq[i].player["blue"]->sword=max(cityseq[i].player["blue"]->bomb,cityseq[i].player["blue"]->arrow)+1;
                            cityseq[i].player["blue"]->w.push_back(new weapon(*weaponPool[0],cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack));
                            cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->sword]->attack=cityseq[i].player["red"]->w[cityseq[i].player["red"]->sword]->attack;
                        }
                        if(cityseq[i].player["blue"]->bomb<0&&cityseq[i].player["red"]->bomb>=0)
                        {
                            cityseq[i].player["blue"]->bomb=max(cityseq[i].player["blue"]->sword,cityseq[i].player["blue"]->arrow)+1;
                            cityseq[i].player["blue"]->w.push_back(new weapon(*weaponPool[1],r));
                        }
                        if(cityseq[i].player["blue"]->arrow<0&&cityseq[i].player["red"]->arrow>=0)
                        {
                            cityseq[i].player["blue"]->arrow=max(cityseq[i].player["blue"]->sword,cityseq[i].player["blue"]->bomb)+1;
                            cityseq[i].player["blue"]->w.push_back(new weapon(*weaponPool[2],r));
                            cityseq[i].player["blue"]->w[cityseq[i].player["blue"]->arrow]->use=cityseq[i].player["red"]->w[cityseq[i].player["red"]->arrow]->use;
                        }
                    }
                    cityseq[i].lastwinner=cityseq[i].thiswinner;
                    cityseq[i].thiswinner=-1;
                }
            }
        }
        if(cityseq[i].changeflag()) cout<<i<<endl;
    }
    refresh();
    for(int i=1;i<=n;i++)
    {
        if(blue.element<8) break;
        if(cityseq[i].win==-1&&cityseq[i].player["blue"]!=NULL)
        {
            cityseq[i].player["blue"]->elements+=8;
            blue.element-=8;
            cityseq[i].win=0;
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(red.element<8) break;
        if(cityseq[i].win==1&&cityseq[i].player["red"]!=NULL)
        {
            cityseq[i].player["red"]->elements+=8;
            red.element-=8;
            cityseq[i].win=0;
        }
    }
}
int main()
{
    int cases;
    cin>>cases;
    for(int C=1;C<=cases;C++)
    {
        bool f=0;
        rednum=0;
        bluenum=0;
        //city cityseq[50];
        cout<<"Case "<<C<<":"<<endl;
        cin>>m>>n>>r>>k>>T;
        for(int i=0;i<=4;i++)
            cin>>soldierlife[i];
        for(int i=0;i<=4;i++)
            cin>>soldierattack[i];
        red=HeadQuarter(0,"red",m,redSeq);
        blue=HeadQuarter(1,"blue",m,blueSeq);
        for(t=0;t<=T;t++)
        {
            if(t%60==0)
            {
                red.born();
                blue.born();
                refresh();
            }
            else if(t%60==5)
            {
                escape();
                refresh();
            }
            else if(t%60==10)
            {
                f=march();
                if(f) break;
            }
            else if(t%60==20)
            {
                for(int i=1;i<=n;i++)
                    cityseq[i].elements+=10;
            }
            else if(t%60==30)
            {
                refresh();
                for(int i=1;i<=n;i++)
                {
                    if((cityseq[i].player["red"]!=NULL&&cityseq[i].player["blue"]==NULL)) 
                    {
                        red.element+=cityseq[i].elements;
                        cout<<setfill('0')<<setw(3)<<t/60<< ":30 red "<<cityseq[i].player["red"]->name<<" "<<cityseq[i].player["red"]->num<<" earned "<<cityseq[i].elements<<" elements for his headquarter"<<endl;
                        cityseq[i].elements=0;
                    }
                    else if((cityseq[i].player["blue"]!=NULL&&cityseq[i].player["red"]==NULL))  
                    {
                        blue.element+=cityseq[i].elements;
                        cout<<setfill('0')<<setw(3)<<t/60<< ":30 blue "<<cityseq[i].player["blue"]->name<<" "<<cityseq[i].player["blue"]->num<<" earned "<<cityseq[i].elements<<" elements for his headquarter"<<endl;
                        cityseq[i].elements=0;
                    }
                }
            }
            else if(t%60==35)
            {
                shot();
            }
            else if(t%60==38)
            {
                usebomb();
            }
            else if(t%60==40)
            {
                battle();
                refresh();
            }
            else if(t%60==50)
            {
                elementreport();
            }
            else if(t%60==55)
            {
                for(int i=1;i<=n+1;i++)
                {
                    if(cityseq[i].player["red"]!=NULL&&cityseq[i].player["red"]->elements>0) 
                    {
                        cout<<setfill('0')<<setw(3)<<t/60<<":55 ";
                        cityseq[i].player["red"]->reportweapon();
                    }
                }
                for(int i=0;i<=n;i++)
                {
                    if(cityseq[i].player["blue"]!=NULL&&cityseq[i].player["blue"]->elements>0) 
                    {
                        cout<<setfill('0')<<setw(3)<<t/60<<":55 ";
                        cityseq[i].player["blue"]->reportweapon();
                    }
                }
            }
        }
        soldierpool.clear();
        for(int i=0;i<=n+1;i++)
        {
            cityseq[i].player["red"]=NULL;
            cityseq[i].player["blue"]=NULL;
            cityseq[i].flag=0;
            cityseq[i].lastwinner=0;
            cityseq[i].thiswinner=0;
            cityseq[i].elements=0;
            cityseq[i].win=0;
        }
    }
    return 0;
}