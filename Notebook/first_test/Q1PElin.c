/*************************************************************
* AceGen    7.303 MacOSX (3 Aug 21)                          *
*           Co. J. Korelc  2020           3 Jan 22 15:53:40  *
**************************************************************
User     : Full professional version
Notebook : Chemomech_ACM_20-12-2021
Evaluation time                 : 7 s     Mode  : Optimal
Number of formulae              : 165     Method: Automatic
Subroutine                      : SKR size: 1329
Subroutine                      : SPP size: 958
Total size of Mathematica  code : 2287 subexpressions
Total size of C code            : 6078 bytes */
#include "sms.h"

void SKR(double v[432],ElementSpec *es,ElementData *ed,NodeSpec **ns,NodeData **nd,double *rdata,int *idata,double *p,double **s);
void SPP(double v[432],ElementSpec *es,ElementData *ed,NodeSpec **ns,NodeData **nd,double *rdata,int *idata,double **gpost,double **npost);

int MMAInitialisationCode[]={
0,24,123,72,111,108,100,91,78,117,108,108,93,44,32,72,111,108,100,91,78,117,108,108,93,125
};



DLLEXPORT int SMTSetElSpec(ElementSpec *es,int *idata,int ic,int ng)
{ int intc,nd,i;FILE *SMSFile;
  static int pn[11]={1, 2, 3, 4, 0, 1, 2, 3, 4, -1, 0};
  static int dof[8]={2, 2, 2, 2, 1, 1, 1, 1};
  static int nsto[8]={0, 0, 0, 0, 0, 0, 0, 0};

  static int ndat[8]={0, 0, 0, 0, 0, 0, 0, 0};

  static int esdat[1]={0};

  static char *nid[]={"D","D","D","D","p","p",
                       "p","p"};
  static char *gdcs[]={"Kdr -drained bulk modulus","G -shear modulus ","kp -flux constant","M -biot modolus","$[Alpha]$ -biot coefficient"};
  static double defd[]={100e0,50e0,0.1e-1,1000e0,0.75e0,0e0};
  static char *gpcs[]={"$[Epsilon]$xx","$[Epsilon]$xy","$[Epsilon]$yy","$[Sigma]$xx","$[Sigma]$xy","$[Sigma]$yy"};
  static char *npcs[]={"DeformedMeshX","DeformedMeshY","u","v","p"};
  static char *sname[]={""};
  static char *idname[]={""};
  static int idindex[1];
  static char *rdname[]={""};
  static char *cswitch[]={""};
  static int iswitch[1]={0};
  static double dswitch[1]={0e0};
  static int rdindex[1];
  static int nspecs[8];
  static double version[3]={7.303,7.303,12.3};
  static double pnweights[8]={1e0,1e0,1e0,1e0,0e0,0e0,
  0e0,0e0};
  static double rnodes[24]={-1e0,-1e0,0e0,1e0,-1e0,0e0,
  1e0,1e0,0e0,-1e0,1e0,0e0,
  0e0,0e0,0e0,0e0,0e0,0e0,
  0e0,0e0,0e0,0e0,0e0,0e0};
  es->ReferenceNodes=rnodes;
  if(ng==-1) es->Data=defd;
  es->id.NoDomainData=5;
  es->Code="Q1PElin";es->Version=version;
  es->MainTitle="";
  es->SubTitle="";
  es->SubSubTitle="";
  es->Bibliography="";
  es->id.NoDimensions=2;es->id.NoDOFGlobal=12;es->id.NoDOFCondense=0;es->id.NoNodes=8;
  es->id.NoSegmentPoints=10;es->Segments=pn;es->PostNodeWeights=pnweights;
  es->id.NoIntSwitch=0;es->IntSwitch=iswitch;es->id.LocalReKe=0;
  es->id.NoDoubleSwitch=0;es->DoubleSwitch=dswitch;
  es->id.NoCharSwitch=0;es->id.WorkingVectorSize=432;es->CharSwitch=cswitch;
  es->DOFGlobal=dof;es->NodeID=nid;es->id.NoGPostData=6;es->id.NoNPostData=5;
  es->id.SymmetricTangent=1;es->id.PostIterationCall=0;es->id.DOFScaling=0;
  es->Topology="Q1";es->DomainDataNames=gdcs;es->GPostNames=gpcs;es->NPostNames=npcs;
  es->AdditionalNodes="Function[{x1, x2, x3, x4}, {x1, x2, x3, x4}]";
  es->AdditionalGraphics="{Null,Null,Null}";
  es->MMAInitialisation=MMAInitialisationCode;
  es->MMANextStep="";
  es->MMAStepBack="";
  es->MMAPreIteration="";
  es->IDataNames=idname;es->IDataIndex=idindex;es->RDataNames=rdname;es->RDataIndex=rdindex;
  es->id.NoIData=0;es->id.NoRData=0;
  es->id.ShapeSensitivity=0; es->id.EBCSensitivity=0;es->id.SensitivityOrder=0;
  es->id.NoSensNames=0;es->SensitivityNames=sname;es->NodeSpecs=nspecs;
  es->user.SPP=SPP;es->user.SKR=SKR;

  es->id.DefaultIntegrationCode=2;
  if(ic==-1){intc=2;} else {intc=ic;};
  es->id.IntCode=intc;
  SMTMultiIntPoints(&intc,idata,&es->id.NoIntPoints,
      &es->id.NoIntPointsA,&es->id.NoIntPointsB,&es->id.NoIntPointsC,0);
  es->id.NoAdditionalData=(int)(0);
  es->id.NoTimeStorage=(int)(0);
  es->id.NoElementData=(int)(0);


  es->NoNodeStorage=nsto;es->NoNodeData=ndat;
  
  es->ExtraSensitivityData=esdat;
  if(1){
   return 0;
  }else{
   return 1;
  };
};


/******************* S U B R O U T I N E *********************/
void SKR(double v[432],ElementSpec *es,ElementData *ed,NodeSpec **ns
     ,NodeData **nd,double *rdata,int *idata,double *p,double **s)
{
int i1,i2,i9,i128;
v[116]=rdata[RD_TimeIncrement];
v[104]=nd[7]->ap[0];
v[103]=nd[6]->ap[0];
v[102]=nd[5]->ap[0];
v[101]=nd[4]->ap[0];
v[100]=nd[3]->ap[1];
v[99]=nd[3]->ap[0];
v[98]=nd[2]->ap[1];
v[97]=nd[2]->ap[0];
v[96]=nd[1]->ap[1];
v[95]=nd[1]->ap[0];
v[94]=nd[0]->ap[1];
v[93]=nd[0]->ap[0];
v[40]=nd[7]->at[0];
v[39]=nd[6]->at[0];
v[38]=nd[5]->at[0];
v[37]=nd[4]->at[0];
v[36]=nd[3]->at[1];
v[35]=nd[3]->at[0];
v[34]=nd[2]->at[1];
v[33]=nd[2]->at[0];
v[32]=nd[1]->at[1];
v[31]=nd[1]->at[0];
v[30]=nd[0]->at[1];
v[29]=nd[0]->at[0];
v[20]=nd[3]->X[1];
v[19]=nd[3]->X[0];
v[18]=nd[2]->X[1];
v[279]=v[18]-v[20];
v[17]=nd[2]->X[0];
v[281]=v[17]-v[19];
v[16]=nd[1]->X[1];
v[275]=v[16]-v[18];
v[15]=nd[1]->X[0];
v[277]=v[15]-v[17];
v[14]=nd[0]->X[1];
v[278]=v[14]-v[16];
v[274]=v[14]-v[20];
v[13]=nd[0]->X[0];
v[280]=v[13]-v[15];
v[276]=v[13]-v[19];
v[7]=es->Data[4];
v[6]=es->Data[3];
v[5]=es->Data[2];
v[4]=es->Data[1];
v[273]=2e0*v[4];
v[130]=es->Data[0]+(-2e0/3e0)*v[4];
i1=es->id.NoIntPoints;
for(i2=1;i2<=i1;i2++){
 i9=4*(-1+i2);
 v[8]=es->IntPoints[i9];
 v[46]=1e0-v[8];
 v[52]=-0.25e0*v[46];
 v[44]=1e0+v[8];
 v[53]=-0.25e0*v[44];
 v[58]=v[274]*v[52]+v[275]*v[53];
 v[56]=v[276]*v[52]+v[277]*v[53];
 v[10]=es->IntPoints[1+i9];
 v[54]=(1e0+v[10])/4e0;
 v[51]=(-1e0+v[10])/4e0;
 v[57]=v[278]*v[51]+v[279]*v[54];
 v[55]=v[280]*v[51]+v[281]*v[54];
 v[12]=es->IntPoints[3+i9];
 v[41]=-(v[46]*v[51]);
 v[43]=-(v[44]*v[51]);
 v[45]=v[44]*v[54];
 v[48]=v[46]*v[54];
 v[59]=-(v[56]*v[57])+v[55]*v[58];
 v[62]=-(v[58]/v[59]);
 v[76]=-(v[54]*v[62]);
 v[68]=-(v[51]*v[62]);
 v[63]=v[56]/v[59];
 v[79]=-(v[54]*v[63]);
 v[70]=-(v[51]*v[63]);
 v[64]=-(v[57]/v[59]);
 v[77]=v[52]*v[64];
 v[72]=v[53]*v[64];
 v[65]=v[55]/v[59];
 v[80]=v[52]*v[65];
 v[74]=v[53]*v[65];
 v[66]=v[68]+v[77];
 v[67]=v[70]+v[80];
 v[69]=-v[68]+v[72];
 v[71]=-v[70]+v[74];
 v[73]=-v[72]+v[76];
 v[75]=-v[74]+v[79];
 v[78]=-v[76]-v[77];
 v[81]=-v[79]-v[80];
 v[86]=v[29]*v[66]+v[31]*v[69]+v[33]*v[73]+v[35]*v[78];
 v[134]=v[4]*(v[30]*v[66]+v[29]*v[67]+v[32]*v[69]+v[31]*v[71]+v[34]*v[73]+v[33]*v[75]+v[36]*v[78]
  +v[35]*v[81]);
 v[88]=v[30]*v[67]+v[32]*v[71]+v[34]*v[75]+v[36]*v[81];
 v[89]=v[37]*v[41]+v[38]*v[43]+v[39]*v[45]+v[40]*v[48];
 v[120]=-((v[101]*v[41]+v[102]*v[43]+v[103]*v[45]+v[104]*v[48]-v[89]+v[6]*v[7]*(v[100]*v[81]-v[86]
  -v[88]+v[66]*v[93]+v[67]*v[94]+v[69]*v[95]+v[71]*v[96]+v[73]*v[97]+v[75]*v[98]+v[78]*v[99]))/
  (v[116]*v[6]));
 v[121]=v[5]*(v[37]*v[66]+v[38]*v[69]+v[39]*v[73]+v[40]*v[78]);
 v[122]=v[5]*(v[37]*v[67]+v[38]*v[71]+v[39]*v[75]+v[40]*v[81]);
 v[131]=v[130]*(v[86]+v[88])-v[7]*v[89];
 v[132]=v[131]+v[273]*v[88];
 v[133]=v[131]+v[273]*v[86];
 v[321]=v[133]*v[66]+v[134]*v[67];
 v[322]=v[134]*v[66]+v[132]*v[67];
 v[323]=v[133]*v[69]+v[134]*v[71];
 v[324]=v[134]*v[69]+v[132]*v[71];
 v[325]=v[133]*v[73]+v[134]*v[75];
 v[326]=v[134]*v[73]+v[132]*v[75];
 v[327]=v[133]*v[78]+v[134]*v[81];
 v[328]=v[134]*v[78]+v[132]*v[81];
 v[329]=v[120]*v[41]+v[121]*v[66]+v[122]*v[67];
 v[330]=v[120]*v[43]+v[121]*v[69]+v[122]*v[71];
 v[331]=v[120]*v[45]+v[121]*v[73]+v[122]*v[75];
 v[332]=v[120]*v[48]+v[121]*v[78]+v[122]*v[81];
 for(i128=1;i128<=12;i128++){
  p[i128-1]+=v[12]*v[320+i128]*v[59];
 };/* end for */
};/* end for */
};

/******************* S U B R O U T I N E *********************/
void SPP(double v[432],ElementSpec *es,ElementData *ed,NodeSpec **ns
     ,NodeData **nd,double *rdata,int *idata,double **gpost,double **npost)
{
int i138,i139,i146;
v[173]=nd[3]->at[1];
v[172]=nd[3]->at[0];
v[171]=nd[2]->at[1];
v[170]=nd[2]->at[0];
v[169]=nd[1]->at[1];
v[168]=nd[1]->at[0];
v[167]=nd[0]->at[1];
v[166]=nd[0]->at[0];
v[157]=nd[3]->X[1];
v[156]=nd[3]->X[0];
v[155]=nd[2]->X[1];
v[288]=v[155]-v[157];
v[154]=nd[2]->X[0];
v[290]=v[154]-v[156];
v[153]=nd[1]->X[1];
v[284]=v[153]-v[155];
v[152]=nd[1]->X[0];
v[286]=v[152]-v[154];
v[151]=nd[0]->X[1];
v[287]=v[151]-v[153];
v[283]=v[151]-v[157];
v[150]=nd[0]->X[0];
v[289]=v[150]-v[152];
v[285]=v[150]-v[156];
v[141]=es->Data[1];
v[282]=2e0*v[141];
v[265]=es->Data[0]+(-2e0/3e0)*v[141];
i138=es->id.NoIntPoints;
for(i139=1;i139<=i138;i139++){
 i146=4*(-1+i139);
 v[145]=es->IntPoints[i146];
 v[189]=(-1e0+v[145])/4e0;
 v[190]=(-1e0-v[145])/4e0;
 v[195]=v[189]*v[283]+v[190]*v[284];
 v[193]=v[189]*v[285]+v[190]*v[286];
 v[147]=es->IntPoints[1+i146];
 v[191]=(1e0+v[147])/4e0;
 v[188]=(-1e0+v[147])/4e0;
 v[194]=v[188]*v[287]+v[191]*v[288];
 v[192]=v[188]*v[289]+v[191]*v[290];
 v[196]=-(v[193]*v[194])+v[192]*v[195];
 v[199]=-(v[195]/v[196]);
 v[213]=-(v[191]*v[199]);
 v[205]=-(v[188]*v[199]);
 v[200]=v[193]/v[196];
 v[216]=-(v[191]*v[200]);
 v[207]=-(v[188]*v[200]);
 v[201]=-(v[194]/v[196]);
 v[214]=v[189]*v[201];
 v[209]=v[190]*v[201];
 v[202]=v[192]/v[196];
 v[217]=v[189]*v[202];
 v[211]=v[190]*v[202];
 v[203]=v[205]+v[214];
 v[204]=v[207]+v[217];
 v[206]=-v[205]+v[209];
 v[208]=-v[207]+v[211];
 v[210]=-v[209]+v[213];
 v[212]=-v[211]+v[216];
 v[215]=-v[213]-v[214];
 v[218]=-v[216]-v[217];
 v[223]=v[166]*v[203]+v[168]*v[206]+v[170]*v[210]+v[172]*v[215];
 v[224]=(v[167]*v[203]+v[166]*v[204]+v[169]*v[206]+v[168]*v[208]+v[171]*v[210]+v[170]*v[212]
  +v[173]*v[215]+v[172]*v[218])/2e0;
 v[225]=v[167]*v[204]+v[169]*v[208]+v[171]*v[212]+v[173]*v[218];
 v[268]=(v[223]+v[225])*v[265];
 gpost[i139-1][0]=v[223];
 gpost[i139-1][1]=v[224];
 gpost[i139-1][2]=v[225];
 gpost[i139-1][3]=v[268]+v[223]*v[282];
 gpost[i139-1][4]=v[224]*v[282];
 gpost[i139-1][5]=v[268]+v[225]*v[282];
};/* end for */
npost[0][0]=v[166];
npost[1][0]=v[168];
npost[2][0]=v[170];
npost[3][0]=v[172];
npost[0][1]=v[167];
npost[1][1]=v[169];
npost[2][1]=v[171];
npost[3][1]=v[173];
npost[0][2]=v[166];
npost[1][2]=v[168];
npost[2][2]=v[170];
npost[3][2]=v[172];
npost[0][3]=v[167];
npost[1][3]=v[169];
npost[2][3]=v[171];
npost[3][3]=v[173];
npost[0][4]=nd[4]->at[0];
npost[1][4]=nd[5]->at[0];
npost[2][4]=nd[6]->at[0];
npost[3][4]=nd[7]->at[0];
};
