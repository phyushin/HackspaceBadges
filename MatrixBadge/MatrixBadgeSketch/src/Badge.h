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
  Badge(char,bool,bool,int);
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
