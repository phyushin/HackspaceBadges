#define idPos   0
#define mindfreePos 1
#define choiceMadePos 2
#define choicePos 3
#define freeMindsBasePos 4

class Badge{

private:

  bool m_mindFree;
  bool m_choiceMade;
  char m_id;
  int  m_choice;
  int  m_freeMinds[30];

public:

  Badge ();
  Badge(char,bool,bool,int,int);
  void Set_MindFree(bool);
  void Set_ChoiceMade(bool);
  void Set_ID(char);
  void Set_Choice(int);
  void Set_FreeMind(int,char);

  bool Get_MindFree();
  bool Get_ChoiceMade();
  char Get_ID();
  int Get_Choice();
  char Get_FreeMind(int);
};
  /*
  void Set_ChoiceMade(bool p_choiceMade){
    m_choiceMade = p_choiceMade;
  }

  void Set_ID(char p_id){
    m_id = p_id;
  }

  void Set_Choice(int p_choice){
    m_choice = p_choice;
  }

  void Set_freeMinds(int p_index,char val){
      m_freeMinds[p_index]=val;
  }

  bool Get_ChoiceMade(){
    return m_choiceMade;
  }

  bool Get_MindFree(){
    return m_mindFree;
  }

  char Get_ID(){
    return m_id;
  }

  int Get_Choice(){
    return m_choice;
  }

  int Get_FreeMind(int index){
    return m_freeMinds[index];
  }

  Badge::Badge(){
    m_mindFree=false;
    m_choiceMade=false;
    m_id='a';
    m_choice=1;
  }

};

Badge::Set_MindFree(bool p_mindFree){
  m_mindFree = p_mindFree;
}
typedef struct {
    char id;
    bool mindFree;
    bool choiceMade;
    int choice;
    int freeMinds[30];
  } badge_struct;
*/
