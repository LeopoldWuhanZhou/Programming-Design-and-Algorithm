#include<iostream>
#include<string>
using namespace std;
int caseNum, M, red, blue;
int life[5];
int redSeq[5]={2,3,4,1,0}, blueSeq[5]={3,0,1,2,4};
string Name[5]={"dragon","ninja","iceman","lion","wolf"};
int main()
{
    cin>>caseNum;
    int n=1;
    while(n<=caseNum)
    {
        cout<<"Case:"<<n<<endl;
        cin>>M>>life[0]>>life[1]>>life[2]>>life[3]>>life[4];
        red = M;
        blue = M;
        int t=0;
        int redNum=0, blueNum=0;
        int rednow=0, bluenow=0;
        int rednum[5] = {0, 0, 0, 0, 0};
        int bluenum[5] = {0, 0, 0, 0, 0};
        bool redflag = 1, blueflag = 1;
        while (redflag || blueflag)
        {
            if(redflag)
            {
                if(red>=life[redSeq[rednow]])
                {
                    red-=life[redSeq[rednow]];
                    redNum++;
                    rednum[redSeq[rednow]]++;
                    if(t<=9) cout<<"00"<<t;
                    else if(t<=99) cout<<"0"<<t;
                    else cout<<t;
                    cout<<" red "<<Name[redSeq[rednow]]<<" "<<redNum<<" born with strength "<<life[redSeq[rednow]]<<","<<rednum[redSeq[rednow]]<<" "<<Name[redSeq[rednow]]<<" in red headquarter"<<endl;
                    rednow=(rednow+1)%5;
                }
                else
                {
                    for(int i=0;i<5;i++)
                    {
                        rednow=(rednow+1)%5;
                        if(red>=life[redSeq[rednow]])
                        {
                            red-=life[redSeq[rednow]];
                            redNum++;
                            rednum[redSeq[rednow]]++;
                            if(t<=9) cout<<"00"<<t;
                            else if(t<=99) cout<<"0"<<t;
                            else cout<<t;
                            cout<<" red "<<Name[redSeq[rednow]]<<" "<<redNum<<" born with strength "<<life[redSeq[rednow]]<<","<<rednum[redSeq[rednow]]<<" "<<Name[redSeq[rednow]]<<" in red headquarter"<<endl;
                            break;
                        }
                        if(i==4)
                        {
                            redflag = 0;
                            red = 0;
                            break;
                        }
                    }
                    if(redflag) rednow=(rednow+1)%5;
                    else
                    {
                        if(t<=9) cout<<"00"<<t;
                        else if(t<=99) cout<<"0"<<t;
                        else cout<<t;
                        cout<<" red headquarter stops making warriors"<<endl;
                    }
                }
            }
            if(blueflag)
            {
                if(blue>=life[blueSeq[bluenow]])
                {
                    blue-=life[blueSeq[bluenow]];
                    blueNum++;
                    bluenum[blueSeq[bluenow]]++;
                    if(t<=9) cout<<"00"<<t;
                    else if(t<=99) cout<<"0"<<t;
                    else cout<<t;
                    cout<<" blue "<<Name[blueSeq[bluenow]]<<" "<<blueNum<<" born with strength "<<life[blueSeq[bluenow]]<<","<<bluenum[blueSeq[bluenow]]<<" "<<Name[blueSeq[bluenow]]<<" in blue headquarter"<<endl;
                    bluenow=(bluenow+1)%5;
                }
                else
                {
                    for(int i=0;i<5;i++)
                    {
                        bluenow=(bluenow+1)%5;
                        if(blue>=life[blueSeq[bluenow]])
                        {
                            blue-=life[blueSeq[bluenow]];
                            blueNum++;
                            bluenum[blueSeq[bluenow]]++;
                            if(t<=9) cout<<"00"<<t;
                            else if(t<=99) cout<<"0"<<t;
                            else cout<<t;
                            cout<<" blue "<<Name[blueSeq[bluenow]]<<" "<<blueNum<<" born with strength "<<life[blueSeq[bluenow]]<<","<<bluenum[blueSeq[bluenow]]<<" "<<Name[blueSeq[bluenow]]<<" in blue headquarter"<<endl;
                            break;
                        }
                        if(i==4)
                        {
                            blueflag = 0;
                            blue = 0;
                            break;
                        }
                    }
                    if(blueflag) bluenow=(bluenow+1)%5;
                    else
                    {
                        if(t<=9) cout<<"00"<<t;
                        else if(t<=99) cout<<"0"<<t;
                        else cout<<t;
                        cout<<" blue headquarter stops making warriors"<<endl;
                    }
                }
            }
            t++;
        }
        n++;
    }
    return 0;
}