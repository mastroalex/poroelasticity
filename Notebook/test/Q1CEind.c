/*************************************************************
* AceGen    7.205 MacOSX (15 Jan 21)                         *
*           Co. J. Korelc  2020           20 Dec 21 11:57:21 *
**************************************************************
User     : Full professional version
Notebook : Chemomech_ACM_20-12-2021
Evaluation time                 : 4 s     Mode  : Optimal
Number of formulae              : 190     Method: Automatic
Subroutine                      : SKR size: 1771
Subroutine                      : SPP size: 1166
Total size of Mathematica  code : 2937 subexpressions
Total size of C code            : 8253 bytes */
#include "sms.h"

void SKR(double v[551],ElementSpec *es,ElementData *ed,NodeSpec **ns,NodeData **nd,double *rdata,int *idata,double *p,double **s);
void SPP(double v[551],ElementSpec *es,ElementData *ed,NodeSpec **ns,NodeData **nd,double *rdata,int *idata,double **gpost,double **npost);

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

  static char *nid[]={"D","D","D","D","c","c",
                       "c","c"};
  static char *gdcs[]={"E -elastic modulus","$[Nu]$ -poisson ratio","kc -flux constant","ceq -equilibrium concentration","$[Mu]$o -reference potential","Dc -diffusivity constant",
                       "m -mobility parameter"};
  static double defd[]={1e0,0.3e0,1e0,1e0,0e0,1e0,
                       1e0,0e0};
  static char *gpcs[]={"$[Epsilon]$xx","$[Epsilon]$xy","$[Epsilon]$yy","$[Sigma]$xx","$[Sigma]$xy","$[Sigma]$yy",
                       "GradMu"};
  static char *npcs[]={"DeformedMeshX","DeformedMeshY","u","v","c"};
  static char *sname[]={""};
  static char *idname[]={""};
  static int idindex[1];
  static char *rdname[]={""};
  static char *cswitch[]={""};
  static int iswitch[1]={0};
  static double dswitch[1]={0e0};
  static int rdindex[1];
  static int nspecs[8];
  static double version[3]={7.205,7.205,12.1};
  static double pnweights[8]={1e0,1e0,1e0,1e0,0e0,0e0,
  0e0,0e0};
  static double rnodes[24]={-1e0,-1e0,0e0,1e0,-1e0,0e0,
  1e0,1e0,0e0,-1e0,1e0,0e0,
  0e0,0e0,0e0,0e0,0e0,0e0,
  0e0,0e0,0e0,0e0,0e0,0e0};
  es->ReferenceNodes=rnodes;
  if(ng==-1) es->Data=defd;
  es->id.NoDomainData=7;
  es->Code="Q1CEind";es->Version=version;
  es->MainTitle="";
  es->SubTitle="";
  es->SubSubTitle="";
  es->Bibliography="";
  es->id.NoDimensions=2;es->id.NoDOFGlobal=12;es->id.NoDOFCondense=0;es->id.NoNodes=8;
  es->id.NoSegmentPoints=10;es->Segments=pn;es->PostNodeWeights=pnweights;
  es->id.NoIntSwitch=0;es->IntSwitch=iswitch;es->id.LocalReKe=0;
  es->id.NoDoubleSwitch=0;es->DoubleSwitch=dswitch;
  es->id.NoCharSwitch=0;es->id.WorkingVectorSize=551;es->CharSwitch=cswitch;
  es->DOFGlobal=dof;es->NodeID=nid;es->id.NoGPostData=7;es->id.NoNPostData=5;
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
void SKR(double v[551],ElementSpec *es,ElementData *ed,NodeSpec **ns
     ,NodeData **nd,double *rdata,int *idata,double *p,double **s)
{
int i1,i2,i12,i128,i139;
v[109]=rdata[RD_TimeIncrement];
v[107]=nd[7]->ap[0];
v[106]=nd[6]->ap[0];
v[105]=nd[5]->ap[0];
v[104]=nd[4]->ap[0];
v[43]=nd[7]->at[0];
v[42]=nd[6]->at[0];
v[41]=nd[5]->at[0];
v[40]=nd[4]->at[0];
v[39]=nd[3]->at[1];
v[38]=nd[3]->at[0];
v[37]=nd[2]->at[1];
v[36]=nd[2]->at[0];
v[35]=nd[1]->at[1];
v[34]=nd[1]->at[0];
v[33]=nd[0]->at[1];
v[32]=nd[0]->at[0];
v[23]=nd[3]->X[1];
v[22]=nd[3]->X[0];
v[21]=nd[2]->X[1];
v[301]=v[21]-v[23];
v[20]=nd[2]->X[0];
v[303]=v[20]-v[22];
v[19]=nd[1]->X[1];
v[297]=v[19]-v[21];
v[18]=nd[1]->X[0];
v[299]=v[18]-v[20];
v[17]=nd[0]->X[1];
v[300]=v[17]-v[19];
v[296]=v[17]-v[23];
v[16]=nd[0]->X[0];
v[302]=v[16]-v[18];
v[298]=v[16]-v[22];
v[9]=es->Data[6];
v[8]=es->Data[5];
v[10]=v[8]/v[9];
v[6]=es->Data[3];
v[291]=2e0*es->Data[1];
v[3]=es->Data[0];
v[111]=v[3]/(2e0+v[291]);
v[293]=2e0*v[111];
v[131]=(-v[293]+v[3]/(1e0-v[291]))/3e0;
i1=es->id.NoIntPoints;
for(i2=1;i2<=i1;i2++){
 i12=4*(-1+i2);
 v[11]=es->IntPoints[i12];
 v[49]=1e0-v[11];
 v[55]=-v[49]/4e0;
 v[47]=1e0+v[11];
 v[56]=-v[47]/4e0;
 v[61]=v[296]*v[55]+v[297]*v[56];
 v[59]=v[298]*v[55]+v[299]*v[56];
 v[13]=es->IntPoints[1+i12];
 v[57]=(1e0+v[13])/4e0;
 v[54]=(-1e0+v[13])/4e0;
 v[60]=v[300]*v[54]+v[301]*v[57];
 v[58]=v[302]*v[54]+v[303]*v[57];
 v[44]=-(v[49]*v[54]);
 v[46]=-(v[47]*v[54]);
 v[48]=v[47]*v[57];
 v[51]=v[49]*v[57];
 v[416]=0e0;
 v[417]=0e0;
 v[418]=0e0;
 v[419]=0e0;
 v[420]=0e0;
 v[421]=0e0;
 v[422]=0e0;
 v[423]=0e0;
 v[424]=v[44];
 v[425]=v[46];
 v[426]=v[48];
 v[427]=v[51];
 v[62]=-(v[59]*v[60])+v[58]*v[61];
 v[294]=es->IntPoints[3+i12]*v[62];
 v[65]=-(v[61]/v[62]);
 v[79]=-(v[57]*v[65]);
 v[71]=-(v[54]*v[65]);
 v[66]=v[59]/v[62];
 v[82]=-(v[57]*v[66]);
 v[73]=-(v[54]*v[66]);
 v[67]=-(v[60]/v[62]);
 v[80]=v[55]*v[67];
 v[75]=v[56]*v[67];
 v[68]=v[58]/v[62];
 v[83]=v[55]*v[68];
 v[77]=v[56]*v[68];
 v[69]=v[71]+v[80];
 v[70]=v[73]+v[83];
 v[72]=-v[71]+v[75];
 v[74]=-v[73]+v[77];
 v[76]=-v[75]+v[79];
 v[78]=-v[77]+v[82];
 v[81]=-v[79]-v[80];
 v[404]=0e0;
 v[405]=0e0;
 v[406]=0e0;
 v[407]=0e0;
 v[408]=0e0;
 v[409]=0e0;
 v[410]=0e0;
 v[411]=0e0;
 v[412]=v[69];
 v[413]=v[72];
 v[414]=v[76];
 v[415]=v[81];
 v[368]=v[69];
 v[369]=0e0;
 v[370]=v[72];
 v[371]=0e0;
 v[372]=v[76];
 v[373]=0e0;
 v[374]=v[81];
 v[375]=0e0;
 v[376]=0e0;
 v[377]=0e0;
 v[378]=0e0;
 v[379]=0e0;
 v[84]=-v[82]-v[83];
 v[428]=v[70];
 v[429]=v[69];
 v[430]=v[74];
 v[431]=v[72];
 v[432]=v[78];
 v[433]=v[76];
 v[434]=v[84];
 v[435]=v[81];
 v[436]=0e0;
 v[437]=0e0;
 v[438]=0e0;
 v[439]=0e0;
 v[392]=0e0;
 v[393]=0e0;
 v[394]=0e0;
 v[395]=0e0;
 v[396]=0e0;
 v[397]=0e0;
 v[398]=0e0;
 v[399]=0e0;
 v[400]=v[70];
 v[401]=v[74];
 v[402]=v[78];
 v[403]=v[84];
 v[380]=0e0;
 v[381]=v[70];
 v[382]=0e0;
 v[383]=v[74];
 v[384]=0e0;
 v[385]=v[78];
 v[386]=0e0;
 v[387]=v[84];
 v[388]=0e0;
 v[389]=0e0;
 v[390]=0e0;
 v[391]=0e0;
 v[89]=v[32]*v[69]+v[34]*v[72]+v[36]*v[76]+v[38]*v[81];
 v[135]=v[111]*(v[33]*v[69]+v[32]*v[70]+v[35]*v[72]+v[34]*v[74]+v[37]*v[76]+v[36]*v[78]+v[39]*v[81]
  +v[38]*v[84]);
 v[91]=v[33]*v[70]+v[35]*v[74]+v[37]*v[78]+v[39]*v[84];
 v[133]=v[131]*(v[89]+v[91]);
 v[92]=v[40]*v[44]+v[41]*v[46]+v[42]*v[48]+v[43]*v[51]+v[6];
 v[122]=-((v[104]*v[44]+v[105]*v[46]+v[106]*v[48]+v[107]*v[51]+v[6]-v[92])/v[109]);
 v[292]=v[10]*v[9];
 v[124]=v[292]*(v[40]*v[69]+v[41]*v[72]+v[42]*v[76]+v[43]*v[81]);
 v[125]=v[292]*(v[40]*v[70]+v[41]*v[74]+v[42]*v[78]+v[43]*v[84]);
 v[132]=v[133]+v[293]*v[91];
 v[134]=v[133]+v[293]*v[89];
 v[352]=v[134]*v[69]+v[135]*v[70];
 v[353]=v[135]*v[69]+v[132]*v[70];
 v[354]=v[134]*v[72]+v[135]*v[74];
 v[355]=v[135]*v[72]+v[132]*v[74];
 v[356]=v[134]*v[76]+v[135]*v[78];
 v[357]=v[135]*v[76]+v[132]*v[78];
 v[358]=v[134]*v[81]+v[135]*v[84];
 v[359]=v[135]*v[81]+v[132]*v[84];
 v[360]=v[122]*v[44]+v[124]*v[69]+v[125]*v[70];
 v[361]=v[122]*v[46]+v[124]*v[72]+v[125]*v[74];
 v[362]=v[122]*v[48]+v[124]*v[76]+v[125]*v[78];
 v[363]=v[122]*v[51]+v[124]*v[81]+v[125]*v[84];
 for(i128=1;i128<=12;i128++){
  v[142]=v[294]*v[367+i128];
  v[143]=v[294]*v[379+i128];
  v[144]=v[294]*v[391+i128];
  v[145]=v[294]*v[403+i128];
  v[295]=v[111]*v[294]*v[427+i128];
  v[150]=v[131]*(v[142]+v[143]);
  v[148]=(v[294]*v[415+i128])/v[109];
  v[149]=v[150]+v[143]*v[293];
  v[151]=v[150]+v[142]*v[293];
  v[440]=v[151]*v[69]+v[295]*v[70];
  v[441]=v[295]*v[69]+v[149]*v[70];
  v[442]=v[151]*v[72]+v[295]*v[74];
  v[443]=v[295]*v[72]+v[149]*v[74];
  v[444]=v[151]*v[76]+v[295]*v[78];
  v[445]=v[295]*v[76]+v[149]*v[78];
  v[446]=v[151]*v[81]+v[295]*v[84];
  v[447]=v[295]*v[81]+v[149]*v[84];
  v[448]=v[148]*v[44]+(v[145]*v[69]+v[144]*v[70])*v[8];
  v[449]=v[148]*v[46]+(v[145]*v[72]+v[144]*v[74])*v[8];
  v[450]=v[148]*v[48]+(v[145]*v[76]+v[144]*v[78])*v[8];
  v[451]=v[148]*v[51]+v[8]*(v[145]*v[81]+v[144]*v[84]);
  p[i128-1]+=v[294]*v[351+i128];
  for(i139=1;i139<=12;i139++){
   s[i128-1][i139-1]+=v[439+i139];
  };/* end for */
 };/* end for */
};/* end for */
};

/******************* S U B R O U T I N E *********************/
void SPP(double v[551],ElementSpec *es,ElementData *ed,NodeSpec **ns
     ,NodeData **nd,double *rdata,int *idata,double **gpost,double **npost)
{
int i155,i156,i166;
v[197]=nd[7]->at[0];
v[196]=nd[6]->at[0];
v[195]=nd[5]->at[0];
v[194]=nd[4]->at[0];
v[193]=nd[3]->at[1];
v[192]=nd[3]->at[0];
v[191]=nd[2]->at[1];
v[190]=nd[2]->at[0];
v[189]=nd[1]->at[1];
v[188]=nd[1]->at[0];
v[187]=nd[0]->at[1];
v[186]=nd[0]->at[0];
v[177]=nd[3]->X[1];
v[176]=nd[3]->X[0];
v[175]=nd[2]->X[1];
v[318]=v[175]-v[177];
v[174]=nd[2]->X[0];
v[320]=v[174]-v[176];
v[173]=nd[1]->X[1];
v[314]=v[173]-v[175];
v[172]=nd[1]->X[0];
v[316]=v[172]-v[174];
v[171]=nd[0]->X[1];
v[317]=v[171]-v[173];
v[313]=v[171]-v[177];
v[170]=nd[0]->X[0];
v[319]=v[170]-v[172];
v[315]=v[170]-v[176];
v[164]=es->Data[5]/es->Data[6];
v[321]=4e0*es->Data[3];
v[310]=2e0*es->Data[1];
v[157]=es->Data[0];
v[311]=(2e0*v[157])/(2e0+v[310]);
v[283]=(v[157]/(1e0-v[310])-v[311])/3e0;
i155=es->id.NoIntPoints;
for(i156=1;i156<=i155;i156++){
 i166=4*(-1+i156);
 v[165]=es->IntPoints[i166];
 v[203]=1e0-v[165];
 v[209]=-v[203]/4e0;
 v[201]=1e0+v[165];
 v[210]=-v[201]/4e0;
 v[215]=v[209]*v[313]+v[210]*v[314];
 v[213]=v[209]*v[315]+v[210]*v[316];
 v[167]=es->IntPoints[1+i166];
 v[204]=1e0+v[167];
 v[211]=v[204]/4e0;
 v[199]=1e0-v[167];
 v[208]=-v[199]/4e0;
 v[214]=v[208]*v[317]+v[211]*v[318];
 v[212]=v[208]*v[319]+v[211]*v[320];
 v[216]=-(v[213]*v[214])+v[212]*v[215];
 v[219]=-(v[215]/v[216]);
 v[233]=-(v[211]*v[219]);
 v[225]=-(v[208]*v[219]);
 v[220]=v[213]/v[216];
 v[236]=-(v[211]*v[220]);
 v[227]=-(v[208]*v[220]);
 v[221]=-(v[214]/v[216]);
 v[234]=v[209]*v[221];
 v[229]=v[210]*v[221];
 v[222]=v[212]/v[216];
 v[237]=v[209]*v[222];
 v[231]=v[210]*v[222];
 v[223]=v[225]+v[234];
 v[224]=v[227]+v[237];
 v[226]=-v[225]+v[229];
 v[228]=-v[227]+v[231];
 v[230]=-v[229]+v[233];
 v[232]=-v[231]+v[236];
 v[235]=-v[233]-v[234];
 v[238]=-v[236]-v[237];
 v[243]=v[186]*v[223]+v[188]*v[226]+v[190]*v[230]+v[192]*v[235];
 v[244]=(v[187]*v[223]+v[186]*v[224]+v[189]*v[226]+v[188]*v[228]+v[191]*v[230]+v[190]*v[232]
  +v[193]*v[235]+v[192]*v[238])/2e0;
 v[245]=v[187]*v[224]+v[189]*v[228]+v[191]*v[232]+v[193]*v[238];
 v[286]=(v[243]+v[245])*v[283];
 v[312]=(4e0*v[164])/(v[199]*(v[195]*v[201]+v[194]*v[203])+(v[196]*v[201]+v[197]*v[203])*v[204]
  +v[321]);
 gpost[i156-1][0]=v[243];
 gpost[i156-1][1]=v[244];
 gpost[i156-1][2]=v[245];
 gpost[i156-1][3]=v[286]+v[243]*v[311];
 gpost[i156-1][4]=v[244]*v[311];
 gpost[i156-1][5]=v[286]+v[245]*v[311];
 gpost[i156-1][6]=(v[194]*v[223]+v[195]*v[226]+v[196]*v[230]+v[197]*v[235])*v[312];
 gpost[i156-1][6]=(v[194]*v[224]+v[195]*v[228]+v[196]*v[232]+v[197]*v[238])*v[312];
};/* end for */
npost[0][0]=v[186];
npost[1][0]=v[188];
npost[2][0]=v[190];
npost[3][0]=v[192];
npost[0][1]=v[187];
npost[1][1]=v[189];
npost[2][1]=v[191];
npost[3][1]=v[193];
npost[0][2]=v[186];
npost[1][2]=v[188];
npost[2][2]=v[190];
npost[3][2]=v[192];
npost[0][3]=v[187];
npost[1][3]=v[189];
npost[2][3]=v[191];
npost[3][3]=v[193];
npost[0][4]=v[194];
npost[1][4]=v[195];
npost[2][4]=v[196];
npost[3][4]=v[197];
};
