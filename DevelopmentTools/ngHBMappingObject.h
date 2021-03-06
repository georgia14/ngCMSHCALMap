#ifndef _ngHBMapObject_H_
#define _ngHBMapObject_H_

#include<string>
//FrontEnd electronics struct
struct ngHBFrontEnd
{
  //interface to BackEnd: 2 side, 18 rbx per side, 4 rm per rbx and 8 rm fibers per rm
  std::string rbx;
  int rm, rm_fiber;
  int qie11_fiber, fiber_ch;
  int qie11, qie11_ch, qie11_id;
  //variables in ROB/Connector
};

//Backend electronics struct
struct ngHBBackEnd
{
  //patch panel information
  int ppcol,pprow,pplc,dodec;
  std::string ppcpl;

  //old htr info, going to be obsolete after 2018 HB re mapping, but keep it for legacy map dumper information
  int crate, htr, htr_fiber;
  std::string fpga;
  int fedid;
  int dcc, spigot, dcc_sl;

  int ucrate, uhtr, uhtr_fiber;
  std::string ufpga;
  int ufedid;

  int fiber_ch;
};

//SiPM struct
struct ngHBSiPM
{
  int wedge;//1,2,3,4...18
  int bv;
};

//Geometry struct
struct ngHBGeometry
{
  int side;
  int eta, phi, depth;
  int dphi;
  std::string subdet;
};

//Trigger tower struct
struct ngHBTriggerTower
{
  int trg_fiber, trg_fiber_ch;
};

class ngHBConstant
{
 public:
  // channels in ngHB
  static const int NchngHB_all = 9216;
  //Front End variables
  //rbx in ngHB, 18 for each side
  static const int NrbxngHB = 18;
  //1,2,3,4 rm per ngHB RBX
  static const int NrmngHB = 4;
  //rm fiber 1,2,3,4,5,6,7,8, in total 8 fibers per rm
  static const int Nrm_fiber = 8;
  //fiber channel is same for both backend electronics and front end electronics, 0,1,2,3,4,5,6,7(since software people like start from 0)
  static const int Nfiber_ch = 8;
  
  //4 QIE11s per ngHB front end rbx
  static const int Nqie11 = 4;
  //QIE11 fiber
  //static const int Nqie11_fiber = 4;
  //12 channels per QIE card, 1 to 12, but qie8 adc is 0 to 5, should we also start from 0 ?
  static const int Nqie11_ch = 16;

  //9 crate shared by HB and HE: 20,21,24,25,30,31,34,35,37
  static const int Ncrate = 9;
  //12 uhtr in each crate, 1,2,3,4,5,6,7,8,9,10,11,12, same as old HF
  static const int Nuhtr = 12, Nuhtr_HB_pure = 4, Nuhtr_HBngHE_mixed = 4, Nuhtr_ngHE_pure = 4;
  //2 fpga flavors top and bottom in htr, while only uHTR in u
  static const int Nufpga = 1;
  //24 in uhtr: 0,1,2,3,4,5,6,7,8,9..22,23; pure HB, 0,1,2,3 and 12 to 23; HB in HBngHE mixed, 2,3,4,5,6,7,8,9; ngHE in HEngHE mixed, 12 to 23;  ngHE in ngHE pure, 1 to 10 and 13 to 22
  static const int Nuhtr_fiber = 24, Nuhtr_fiber_HB_pure = 16, Nuhtr_fiber_HB_HBngHE_mixed = 8, Nuhtr_fiber_ngHE_HBngHE_mixed = 12, Nuhtr_fiber_ngHE_pure = 20;
  //24 in uhtr: 0,1,2,3,4,5,6,7,8,9..22,23; do not know why Dick is interested in 22 10 rather than 20 12 to have a kind of symmetry in HBHE? maybe due to data volumn ???
  //static const int Nuhtr_fiber = 24, Nuhtr_fiber_ngHB_pure = 22, Nuhtr_fiber_ngHB_ngHBngHE_mixed = 10, Nuhtr_fiber_ngHE_HBngHE_mixed = 12, Nuhtr_fiber_ngHE_pure = 20;
  //Number of backend ngHB channels = 9 * (4*22+4*10) * 8 = 9216 
  
  //Geometry variables in ngHB: eta from 1 to 16, phi is 1 to 72, depth 1,2,3,4 from eta 1 to 15, depth 1,2,3 for the eta 16
  static const int NngHBside = 2;
  static const int NngHBphi = 72;
  static const int NngHBeta16 = 1; static const int NngHBeta1to15 = 15;
  static const int NngHBdeptheta16 = 3; static const int NngHBdeptheta1to15 = 4;
  //Number if Geo ngHB channels = 2 * 72 * (1*3+15*4) = 9072
  static const int NngHBCalibChannel = 144;
};
#endif
