/*************************************************************
* AceGen    7.303 MacOSX (3 Aug 21)                          *
*           Co. J. Korelc  2020           3 Jan 22 16:37:26  *
**************************************************************
User     : Full professional version
Notebook : Chemomech_ACM_20-12-2021
Evaluation time                 : 4 s     Mode  : Optimal
Number of formulae              : 186     Method: Automatic
Subroutine                      : SKR size: 1896
Subroutine                      : SPP size: 958
Total size of Mathematica  code : 2854 subexpressions
Total size of C code            : 8046 bytes */
#include "sms.h"

void SKR(double v[548],ElementSpec *es,ElementData *ed,NodeSpec **ns,NodeData **nd,double *rdata,int *idata,double *p,double **s);
void SPP(double v[548],ElementSpec *es,ElementData *ed,NodeSpec **ns,NodeData **nd,double *rdata,int *idata,double **gpost,double **npost);

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
  es->id.NoCharSwitch=0;es->id.WorkingVectorSize=548;es->CharSwitch=cswitch;
  es->DOFGlobal=dof;es->NodeID=nid;es->id.NoGPostData=6;es->id.NoNPostData=5;
  es->id.SymmetricTangent=0;es->id.PostIterationCall=0;es->id.DOFScaling=0;
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
void SKR(double v[548],ElementSpec *es,ElementData *ed,NodeSpec **ns
     ,NodeData **nd,double *rdata,int *idata,double *p,double **s)
{
int i1,i2,i9,i129,i139;
v[118]=rdata[RD_TimeIncrement];
v[105]=nd[7]->ap[0];
v[104]=nd[6]->ap[0];
v[103]=nd[5]->ap[0];
v[102]=nd[4]->ap[0];
v[101]=nd[3]->ap[1];
v[100]=nd[3]->ap[0];
v[99]=nd[2]->ap[1];
v[98]=nd[2]->ap[0];
v[97]=nd[1]->ap[1];
v[96]=nd[1]->ap[0];
v[95]=nd[0]->ap[1];
v[94]=nd[0]->ap[0];
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
v[301]=v[18]-v[20];
v[17]=nd[2]->X[0];
v[303]=v[17]-v[19];
v[16]=nd[1]->X[1];
v[297]=v[16]-v[18];
v[15]=nd[1]->X[0];
v[299]=v[15]-v[17];
v[14]=nd[0]->X[1];
v[300]=v[14]-v[16];
v[296]=v[14]-v[20];
v[13]=nd[0]->X[0];
v[302]=v[13]-v[15];
v[298]=v[13]-v[19];
v[7]=es->Data[4];
v[6]=es->Data[3];
v[294]=1e0/(v[118]*v[6]);
v[5]=es->Data[2];
v[4]=es->Data[1];
v[292]=2e0*v[4];
v[131]=es->Data[0]+(-2e0/3e0)*v[4];
i1=es->id.NoIntPoints;
for(i2=1;i2<=i1;i2++){
 i9=4*(-1+i2);
 v[8]=es->IntPoints[i9];
 v[46]=1e0-v[8];
 v[52]=-0.25e0*v[46];
 v[44]=1e0+v[8];
 v[53]=-0.25e0*v[44];
 v[58]=v[296]*v[52]+v[297]*v[53];
 v[56]=v[298]*v[52]+v[299]*v[53];
 v[10]=es->IntPoints[1+i9];
 v[54]=(1e0+v[10])/4e0;
 v[51]=(-1e0+v[10])/4e0;
 v[57]=v[300]*v[51]+v[301]*v[54];
 v[55]=v[302]*v[51]+v[303]*v[54];
 v[41]=-(v[46]*v[51]);
 v[43]=-(v[44]*v[51]);
 v[45]=v[44]*v[54];
 v[48]=v[46]*v[54];
 v[413]=0e0;
 v[414]=0e0;
 v[415]=0e0;
 v[416]=0e0;
 v[417]=0e0;
 v[418]=0e0;
 v[419]=0e0;
 v[420]=0e0;
 v[421]=v[41];
 v[422]=v[43];
 v[423]=v[45];
 v[424]=v[48];
 v[59]=-(v[56]*v[57])+v[55]*v[58];
 v[293]=es->IntPoints[3+i9]*v[59];
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
 v[401]=0e0;
 v[402]=0e0;
 v[403]=0e0;
 v[404]=0e0;
 v[405]=0e0;
 v[406]=0e0;
 v[407]=0e0;
 v[408]=0e0;
 v[409]=v[66];
 v[410]=v[69];
 v[411]=v[73];
 v[412]=v[78];
 v[365]=v[66];
 v[366]=0e0;
 v[367]=v[69];
 v[368]=0e0;
 v[369]=v[73];
 v[370]=0e0;
 v[371]=v[78];
 v[372]=0e0;
 v[373]=0e0;
 v[374]=0e0;
 v[375]=0e0;
 v[376]=0e0;
 v[81]=-v[79]-v[80];
 v[425]=v[67];
 v[426]=v[66];
 v[427]=v[71];
 v[428]=v[69];
 v[429]=v[75];
 v[430]=v[73];
 v[431]=v[81];
 v[432]=v[78];
 v[433]=0e0;
 v[434]=0e0;
 v[435]=0e0;
 v[436]=0e0;
 v[389]=0e0;
 v[390]=0e0;
 v[391]=0e0;
 v[392]=0e0;
 v[393]=0e0;
 v[394]=0e0;
 v[395]=0e0;
 v[396]=0e0;
 v[397]=v[67];
 v[398]=v[71];
 v[399]=v[75];
 v[400]=v[81];
 v[377]=0e0;
 v[378]=v[67];
 v[379]=0e0;
 v[380]=v[71];
 v[381]=0e0;
 v[382]=v[75];
 v[383]=0e0;
 v[384]=v[81];
 v[385]=0e0;
 v[386]=0e0;
 v[387]=0e0;
 v[388]=0e0;
 v[86]=v[29]*v[66]+v[31]*v[69]+v[33]*v[73]+v[35]*v[78];
 v[135]=v[4]*(v[30]*v[66]+v[29]*v[67]+v[32]*v[69]+v[31]*v[71]+v[34]*v[73]+v[33]*v[75]+v[36]*v[78]
  +v[35]*v[81]);
 v[88]=v[30]*v[67]+v[32]*v[71]+v[34]*v[75]+v[36]*v[81];
 v[89]=v[86]+v[88];
 v[90]=v[37]*v[41]+v[38]*v[43]+v[39]*v[45]+v[40]*v[48];
 v[122]=v[294]*(-(v[102]*v[41])-v[103]*v[43]-v[104]*v[45]-v[105]*v[48]+v[90]-v[6]*v[7]*
  (v[100]*v[78]+v[101]*v[81]-v[89]+v[66]*v[94]+v[67]*v[95]+v[69]*v[96]+v[71]*v[97]+v[73]*v[98]
  +v[75]*v[99]));
 v[123]=v[5]*(v[37]*v[66]+v[38]*v[69]+v[39]*v[73]+v[40]*v[78]);
 v[124]=v[5]*(v[37]*v[67]+v[38]*v[71]+v[39]*v[75]+v[40]*v[81]);
 v[132]=v[131]*v[89]-v[7]*v[90];
 v[133]=v[132]+v[292]*v[88];
 v[134]=v[132]+v[292]*v[86];
 v[349]=v[134]*v[66]+v[135]*v[67];
 v[350]=v[135]*v[66]+v[133]*v[67];
 v[351]=v[134]*v[69]+v[135]*v[71];
 v[352]=v[135]*v[69]+v[133]*v[71];
 v[353]=v[134]*v[73]+v[135]*v[75];
 v[354]=v[135]*v[73]+v[133]*v[75];
 v[355]=v[134]*v[78]+v[135]*v[81];
 v[356]=v[135]*v[78]+v[133]*v[81];
 v[357]=v[122]*v[41]+v[123]*v[66]+v[124]*v[67];
 v[358]=v[122]*v[43]+v[123]*v[69]+v[124]*v[71];
 v[359]=v[122]*v[45]+v[123]*v[73]+v[124]*v[75];
 v[360]=v[122]*v[48]+v[123]*v[78]+v[124]*v[81];
 for(i129=1;i129<=12;i129++){
  v[142]=v[293]*v[364+i129];
  v[143]=v[293]*v[376+i129];
  v[144]=v[293]*v[388+i129];
  v[145]=v[293]*v[400+i129];
  v[146]=v[293]*v[412+i129];
  v[295]=v[293]*v[4]*v[424+i129];
  v[148]=v[142]+v[143];
  v[149]=v[146]*v[294]-v[148]*v[7];
  v[150]=v[131]*v[148]+(v[146]*v[7])/v[118];
  v[151]=v[150]+v[143]*v[292];
  v[152]=v[150]+v[142]*v[292];
  v[437]=v[152]*v[66]+v[295]*v[67];
  v[438]=v[295]*v[66]+v[151]*v[67];
  v[439]=v[152]*v[69]+v[295]*v[71];
  v[440]=v[295]*v[69]+v[151]*v[71];
  v[441]=v[152]*v[73]+v[295]*v[75];
  v[442]=v[295]*v[73]+v[151]*v[75];
  v[443]=v[152]*v[78]+v[295]*v[81];
  v[444]=v[295]*v[78]+v[151]*v[81];
  v[445]=v[149]*v[41]+v[5]*(v[145]*v[66]+v[144]*v[67]);
  v[446]=v[149]*v[43]+v[5]*(v[145]*v[69]+v[144]*v[71]);
  v[447]=v[149]*v[45]+v[5]*(v[145]*v[73]+v[144]*v[75]);
  v[448]=v[149]*v[48]+v[5]*(v[145]*v[78]+v[144]*v[81]);
  p[i129-1]+=v[293]*v[348+i129];
  for(i139=1;i139<=12;i139++){
   s[i129-1][i139-1]+=v[436+i139];
  };/* end for */
 };/* end for */
};/* end for */
};

/******************* S U B R O U T I N E *********************/
void SPP(double v[548],ElementSpec *es,ElementData *ed,NodeSpec **ns
     ,NodeData **nd,double *rdata,int *idata,double **gpost,double **npost)
{
int i156,i157,i164;
v[191]=nd[3]->at[1];
v[190]=nd[3]->at[0];
v[189]=nd[2]->at[1];
v[188]=nd[2]->at[0];
v[187]=nd[1]->at[1];
v[186]=nd[1]->at[0];
v[185]=nd[0]->at[1];
v[184]=nd[0]->at[0];
v[175]=nd[3]->X[1];
v[174]=nd[3]->X[0];
v[173]=nd[2]->X[1];
v[316]=v[173]-v[175];
v[172]=nd[2]->X[0];
v[318]=v[172]-v[174];
v[171]=nd[1]->X[1];
v[312]=v[171]-v[173];
v[170]=nd[1]->X[0];
v[314]=v[170]-v[172];
v[169]=nd[0]->X[1];
v[315]=v[169]-v[171];
v[311]=v[169]-v[175];
v[168]=nd[0]->X[0];
v[317]=v[168]-v[170];
v[313]=v[168]-v[174];
v[159]=es->Data[1];
v[310]=2e0*v[159];
v[284]=es->Data[0]+(-2e0/3e0)*v[159];
i156=es->id.NoIntPoints;
for(i157=1;i157<=i156;i157++){
 i164=4*(-1+i157);
 v[163]=es->IntPoints[i164];
 v[207]=(-1e0+v[163])/4e0;
 v[208]=(-1e0-v[163])/4e0;
 v[213]=v[207]*v[311]+v[208]*v[312];
 v[211]=v[207]*v[313]+v[208]*v[314];
 v[165]=es->IntPoints[1+i164];
 v[209]=(1e0+v[165])/4e0;
 v[206]=(-1e0+v[165])/4e0;
 v[212]=v[206]*v[315]+v[209]*v[316];
 v[210]=v[206]*v[317]+v[209]*v[318];
 v[214]=-(v[211]*v[212])+v[210]*v[213];
 v[217]=-(v[213]/v[214]);
 v[231]=-(v[209]*v[217]);
 v[223]=-(v[206]*v[217]);
 v[218]=v[211]/v[214];
 v[234]=-(v[209]*v[218]);
 v[225]=-(v[206]*v[218]);
 v[219]=-(v[212]/v[214]);
 v[232]=v[207]*v[219];
 v[227]=v[208]*v[219];
 v[220]=v[210]/v[214];
 v[235]=v[207]*v[220];
 v[229]=v[208]*v[220];
 v[221]=v[223]+v[232];
 v[222]=v[225]+v[235];
 v[224]=-v[223]+v[227];
 v[226]=-v[225]+v[229];
 v[228]=-v[227]+v[231];
 v[230]=-v[229]+v[234];
 v[233]=-v[231]-v[232];
 v[236]=-v[234]-v[235];
 v[241]=v[184]*v[221]+v[186]*v[224]+v[188]*v[228]+v[190]*v[233];
 v[242]=(v[185]*v[221]+v[184]*v[222]+v[187]*v[224]+v[186]*v[226]+v[189]*v[228]+v[188]*v[230]
  +v[191]*v[233]+v[190]*v[236])/2e0;
 v[243]=v[185]*v[222]+v[187]*v[226]+v[189]*v[230]+v[191]*v[236];
 v[287]=(v[241]+v[243])*v[284];
 gpost[i157-1][0]=v[241];
 gpost[i157-1][1]=v[242];
 gpost[i157-1][2]=v[243];
 gpost[i157-1][3]=v[287]+v[241]*v[310];
 gpost[i157-1][4]=v[242]*v[310];
 gpost[i157-1][5]=v[287]+v[243]*v[310];
};/* end for */
npost[0][0]=v[184];
npost[1][0]=v[186];
npost[2][0]=v[188];
npost[3][0]=v[190];
npost[0][1]=v[185];
npost[1][1]=v[187];
npost[2][1]=v[189];
npost[3][1]=v[191];
npost[0][2]=v[184];
npost[1][2]=v[186];
npost[2][2]=v[188];
npost[3][2]=v[190];
npost[0][3]=v[185];
npost[1][3]=v[187];
npost[2][3]=v[189];
npost[3][3]=v[191];
npost[0][4]=nd[4]->at[0];
npost[1][4]=nd[5]->at[0];
npost[2][4]=nd[6]->at[0];
npost[3][4]=nd[7]->at[0];
};
