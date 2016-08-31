//#include "HBHEMappingObject.h" 
//#include "HFMappingObject.h"
//#include "HOMappingObject.h"
#include <iomanip>

namespace HCALLMapDumper
{
  void printHFLMapObject(                     
                         std::vector<HFFrontEnd> myHFFrontEnd, std::vector<HFBackEnd> myHFBackEnd, std::vector<HFPMTBox> myHFPMTBox, std::vector<HFGeometry> myHFGeometry, std::vector<HFTriggerTower> myHFTriggerTower
                        )
  {
    std::cout << "#Dumping HF LMap Object..." << std::endl;
    std::cout << "#"
              << std::setw(6) <<"Side" << std::setw(6) << "Eta" << std::setw(6) << "Phi" << std::setw(6) << "Depth"
              //<< std::setw(9) << "PMT" << std::setw(9) << "PMT_TYPE" << std::setw(9) << "W_Cable"
              //<< std::setw(6) << "S_PMT" << std::setw(6) << "S_QIE" << std::setw(6) << "R_PMT" << std::setw(6) << "R_QIE"
              << std::setw(9) << "RBX"<< std::setw(9) << "RM" << std::setw(9) << "RM_FI" << std::setw(9) << "FI_CH" << std::setw(9) << "QIE8" << std::setw(9) << "QIE8_CH"
              << std::setw(9) << "uCrate" << std::setw(9) << "uHTR" << std::setw(9) << "uHTR_FI" << std::setw(9) << "FI_CH" << std::endl;

    for(auto i=0; i<myHFFrontEnd.size(); i++)
    {
      std::cout //<< "HFGeometry(side,eta,phi,depth): " 
                << " "
                << std::setw(6) << myHFGeometry.at(i).side << std::setw(6) <<  myHFGeometry.at(i).eta << std::setw(6) << myHFGeometry.at(i).phi << std::setw(6) << myHFGeometry.at(i).depth
                //<< "HFFrontEnd(rbx,rm,rm_fiber,fiber_ch,qie8,qie8_ch): " 
                << std::setw(9) << myHFFrontEnd.at(i).rbx << std::setw(9) << myHFFrontEnd.at(i).rm << std::setw(9) << myHFFrontEnd.at(i).rm_fiber << std::setw(9) << myHFFrontEnd.at(i).fiber_ch << std::setw(9) << myHFFrontEnd.at(i).qie8 << std::setw(9) << myHFFrontEnd.at(i).qie8_ch
                //<< "HFBackEnd(ucrate,uhtr,uhtr_fiber,fiber_ch): " 
                << std::setw(9) << myHFBackEnd.at(i).ucrate << std::setw(9) << myHFBackEnd.at(i).uhtr << std::setw(9) << myHFBackEnd.at(i).uhtr_fiber << std::setw(9) << myHFBackEnd.at(i).fiber_ch
                << std::endl;
    }
    return ;
  }

  void printngHFLMapObject(std::vector<ngHFFrontEnd> myngHFFrontEnd, std::vector<ngHFBackEnd> myngHFBackEnd, std::vector<ngHFPMTBox> myngHFPMTBox, std::vector<ngHFGeometry> myngHFGeometry, std::vector<ngHFTriggerTower> myngHFTriggerTower)
  {
    std::cout << "#Dumping ngHF LMap Object..." << std::endl;
    std::cout << "#"
              << std::setw(6) <<"Side" << std::setw(6) << "Eta" << std::setw(6) << "Phi" << std::setw(6) << "Depth" << std::setw(6) << "Subdet"
              << std::setw(9) << "PMT" << std::setw(9) << "PMT_TYPE" << std::setw(9) << "W_Cable"
              << std::setw(6) << "S_PMT" << std::setw(6) << "S_QIE" << std::setw(6) << "R_PMT" << std::setw(6) << "R_QIE"
              << std::setw(9) << "ngRBX" << std::setw(9) << "QIE10" << std::setw(9) << "QIE10_CH" << std::setw(9) << "QIE10_FI" << std::setw(9) << "FI_CH"
              << std::setw(9) << "uCrate" << std::setw(9) << "uHTR" << std::setw(9) << "uHTR_FI" << std::setw(9) << "FI_CH" << std::endl;


    for(auto i=0; i<myngHFFrontEnd.size(); i++)
    {
      std::cout 
                //<< "ngHFGeometry(side,eta,phi,depth): "
                << " "          
                << std::setw(6) << myngHFGeometry.at(i).side << std::setw(6) << myngHFGeometry.at(i).eta << std::setw(6) << myngHFGeometry.at(i).phi << std::setw(6) << myngHFGeometry.at(i).depth << std::setw(6) << myngHFGeometry.at(i).subdet
                //<< "ngHFPMTBox(PMT, PMT Type, Winchester Cable): "
                << std::setw(9) << myngHFPMTBox.at(i).pmt << std::setw(9) << myngHFPMTBox.at(i).pmt_type << std::setw(9) << myngHFPMTBox.at(i).winchester_cable
                //<< "Winchester Cable, PIN to PIN"
                << std::setw(6) << myngHFPMTBox.at(i).s_coax_pmt << std::setw(6) << myngHFFrontEnd.at(i).s_coax_qie << std::setw(6) << myngHFPMTBox.at(i).r_coax_pmt << std::setw(6) << myngHFFrontEnd.at(i).r_coax_qie
                //<< "ngHFFrontEnd(rbx,rm,rm_fiber,fiber_ch,qie8,qie8_ch): "
                << std::setw(9) << myngHFFrontEnd.at(i).rbx << std::setw(9) << myngHFFrontEnd.at(i).qie10 << std::setw(9) << myngHFFrontEnd.at(i).qie10_ch << std::setw(9) << myngHFFrontEnd.at(i).qie10_fiber << std::setw(9)  << myngHFFrontEnd.at(i).fiber_ch
                //<< "ngHFBackEnd(ucrate,uhtr,uhtr_fiber,fiber_ch): "
                << std::setw(9) << myngHFBackEnd.at(i).ucrate << std::setw(9) << myngHFBackEnd.at(i).uhtr << std::setw(9) << myngHFBackEnd.at(i).uhtr_fiber << std::setw(9) << myngHFBackEnd.at(i).fiber_ch
                << std::endl;
    }
    return ;
  }

  void printngHFEMapObject(std::vector<ngHFFrontEnd> myngHFFrontEnd, std::vector<ngHFBackEnd> myngHFBackEnd, std::vector<ngHFPMTBox> myngHFPMTBox, std::vector<ngHFGeometry> myngHFGeometry, std::vector<ngHFTriggerTower> myngHFTriggerTower)
  { 
    //#       i  cr  sl  tb  dcc  spigot  fiber/slb  fibcha/slbcha  subdet  ieta  iphi  depth
    std::cout << "#Dumping ngHF EMap Object..." << std::endl;
    std::cout << "#"
              << std::setw(10) <<"i" 
              << std::setw(6) << "cr" << std::setw(6) << "sl" << std::setw(6) << "tb" << std::setw(6) << "dcc" << std::setw(8) << "spigot" << std::setw(8) << "fib/slb" << std::setw(12) << "fibch/slbch" 
              << std::setw(8) << "subdet" << std::setw(6) << "eta" << std::setw(6) << "phi" << std::setw(9) << "dep" 
              << std::endl;
    
    for(auto i=0; i<myngHFFrontEnd.size(); i++)
    { 
      std::cout 
                //<< "ngHFGeometry(side,eta,phi,depth): "
                << " " 
                << std::setw(10) << "4200458C"          
                << std::setw(6) << myngHFBackEnd.at(i).ucrate << std::setw(6) << myngHFBackEnd.at(i).uhtr << std::setw(6) << "u" << std::setw(6) << 0 << std::setw(8) << 0 << std::setw(8) << myngHFBackEnd.at(i).uhtr_fiber << std::setw(12) << myngHFBackEnd.at(i).fiber_ch
                << std::setw(8) << myngHFGeometry.at(i).subdet << std::setw(6) << myngHFGeometry.at(i).side * myngHFGeometry.at(i).eta << std::setw(6) << myngHFGeometry.at(i).phi << std::setw(6) << myngHFGeometry.at(i).depth
                << std::endl;
    }
    return ;
  }

  void printngHFFrontEndMapObject(std::vector<ngHFFrontEnd> myngHFFrontEnd, std::vector<ngHFBackEnd> myngHFBackEnd, std::vector<ngHFPMTBox> myngHFPMTBox, std::vector<ngHFGeometry> myngHFGeometry, std::vector<ngHFTriggerTower> myngHFTriggerTower)
  {
    //#       i  cr  sl  tb  dcc  spigot  fiber/slb  fibcha/slbcha  subdet  ieta  iphi  depth
    std::cout << "#Dumping ngHF FrontEnd Map Object..." << std::endl;
    std::cout << "#"
              << std::setw(6) << "eta" << std::setw(6) << "phi" << std::setw(9) << "dep"
              << std::setw(8) << "subdet" 
              << std::setw(6) << "rbx" << std::setw(6) << "rm"
              << std::endl;

    for(auto i=0; i<myngHFFrontEnd.size(); i++)
    {
      std::cout
                //<< "ngHFGeometry(side,eta,phi,depth): "
                << " "
                << std::setw(6) << myngHFGeometry.at(i).side * myngHFGeometry.at(i).eta << std::setw(6) << myngHFGeometry.at(i).phi << std::setw(6) << myngHFGeometry.at(i).depth
                << std::setw(8) << myngHFGeometry.at(i).subdet 
                << std::setw(9) << myngHFFrontEnd.at(i).rbx << std::setw(6) << 0
                << std::endl;
    }
    return ;
  }

  void printngHELMapObject(std::vector<ngHEFrontEnd> myngHEFrontEnd, std::vector<ngHEBackEnd> myngHEBackEnd, std::vector<ngHEPMTBox> myngHEPMTBox, std::vector<ngHEGeometry> myngHEGeometry, std::vector<ngHETriggerTower> myngHETriggerTower)
  {
    std::cout << "#Dumping ngHE LMap Object..." << std::endl;
    std::cout << "#"
              << std::setw(6) <<"Side" << std::setw(6) << "Eta" << std::setw(6) << "Phi" << std::setw(6) << "Depth" << std::setw(6) << "Subdet"
              << std::setw(9) << "ngRBX" << std::setw(9) << "RM" << std::setw(9) << "RM_FI" << std::setw(9) << "FI_CH"
              << std::setw(9) << "uCrate" << std::setw(9) << "uHTR" << std::setw(9) << "uHTR_FI" << std::setw(9) << "FI_CH" << std::endl;
    for(auto i=0; i<myngHEFrontEnd.size(); i++)
    {
      //if( myngHEFrontEnd.at(i).rbx != "ngHEP02" ) continue;
      std::cout
                << " "
                << std::setw(6) << myngHEGeometry.at(i).side << std::setw(6) << myngHEGeometry.at(i).eta << std::setw(6) << myngHEGeometry.at(i).phi << std::setw(6) << myngHEGeometry.at(i).depth << std::setw(6) << myngHEGeometry.at(i).subdet
                << std::setw(9) << myngHEFrontEnd.at(i).rbx << std::setw(9) << myngHEFrontEnd.at(i).rm << std::setw(9) << myngHEFrontEnd.at(i).rm_fiber << std::setw(9) << myngHEFrontEnd.at(i).fiber_ch
                << std::setw(9) << myngHEBackEnd.at(i).ucrate << std::setw(9) << myngHEBackEnd.at(i).uhtr << std::setw(9) << myngHEBackEnd.at(i).uhtr_fiber << std::setw(9) << myngHEBackEnd.at(i).fiber_ch
                << std::endl;
    }
    return ;
  }

  void printngHEEMapObject(std::vector<ngHEFrontEnd> myngHEFrontEnd, std::vector<ngHEBackEnd> myngHEBackEnd, std::vector<ngHEPMTBox> myngHEPMTBox, std::vector<ngHEGeometry> myngHEGeometry, std::vector<ngHETriggerTower> myngHETriggerTower)
  {
    //#       i  cr  sl  tb  dcc  spigot  fiber/slb  fibcha/slbcha  subdet  ieta  iphi  depth
    std::cout << "#Dumping ngHE EMap Object..." << std::endl;
    std::cout << "#"
              << std::setw(10) <<"i"
              << std::setw(6) << "cr" << std::setw(6) << "sl" << std::setw(6) << "tb" << std::setw(6) << "dcc" << std::setw(8) << "spigot" << std::setw(8) << "fib/slb" << std::setw(12) << "fibch/slbch"
              << std::setw(8) << "subdet" << std::setw(6) << "eta" << std::setw(6) << "phi" << std::setw(9) << "dep"
              << std::endl;

    for(auto i=0; i<myngHEFrontEnd.size(); i++)
    {
      if( myngHEGeometry.at(i).subdet == "HEX" ) continue;
      std::cout << " "
                << std::setw(10) << "4200458C"
                << std::setw(6) << myngHEBackEnd.at(i).ucrate << std::setw(6) << myngHEBackEnd.at(i).uhtr << std::setw(6) << "u" << std::setw(6) << 0 << std::setw(8) << 0 << std::setw(8) << myngHEBackEnd.at(i).uhtr_fiber << std::setw(12) << myngHEBackEnd.at(i).fiber_ch
                << std::setw(8) << myngHEGeometry.at(i).subdet << std::setw(6) << myngHEGeometry.at(i).side * myngHEGeometry.at(i).eta << std::setw(6) << myngHEGeometry.at(i).phi << std::setw(6) << myngHEGeometry.at(i).depth
                << std::endl;
    }
    return ;
  }

  void printngHEFrontEndMapObject(std::vector<ngHEFrontEnd> myngHEFrontEnd, std::vector<ngHEBackEnd> myngHEBackEnd, std::vector<ngHEPMTBox> myngHEPMTBox, std::vector<ngHEGeometry> myngHEGeometry, std::vector<ngHETriggerTower> myngHETriggerTower)
  {
    //#       i  cr  sl  tb  dcc  spigot  fiber/slb  fibcha/slbcha  subdet  ieta  iphi  depth
    std::cout << "#Dumping ngHE FrontEnd Map Object..." << std::endl;
    std::cout << "#"
              << std::setw(6) << "eta" << std::setw(6) << "phi" << std::setw(9) << "dep"
              << std::setw(8) << "subdet"
              << std::setw(6) << "rbx" << std::setw(6) << "rm"
              << std::endl;
    
    for(auto i=0; i<myngHEFrontEnd.size(); i++)
    {
      if( myngHEGeometry.at(i).subdet == "HEX" ) continue;
      std::cout
                //<< "ngHEGeometry(side,eta,phi,depth): "
                << " "
                << std::setw(6) << myngHEGeometry.at(i).side * myngHEGeometry.at(i).eta << std::setw(6) << myngHEGeometry.at(i).phi << std::setw(6) << myngHEGeometry.at(i).depth
                << std::setw(8) << myngHEGeometry.at(i).subdet
                << std::setw(9) << myngHEFrontEnd.at(i).rbx << std::setw(6) << myngHEFrontEnd.at(i).rm
                << std::endl;
    }
    return ;
  }
}

/*
namespace HCALEMapXMLDumper
{
  void HFXMLGenerator(
                      std::vector<HFFrontEnd> myHFFrontEnd, std::vector<HFBackEnd> myHFBackEnd, std::vector<HFPMTBox> myHFPMTBox, std::vector<HFGeometry> myHFGeometry, std::vector<HFTriggerTower> myHFTriggerTower
                     )
  { 
    std::cout << "#Dumping HF LMap Object..." << std::endl;
    
    for(auto i=0; i<myHFFrontEnd.size(); i++)
    { 
      std::cout //<< "HFGeometry(side,eta,phi,depth): " 
                << myHFGeometry.at(i).side << " " <<  myHFGeometry.at(i).eta << " " << myHFGeometry.at(i).phi << " " << myHFGeometry.at(i).depth << " "
                //<< "HFFrontEnd(rbx,rm,rm_fiber,fiber_ch,qie8,qie8_ch): " 
                << myHFFrontEnd.at(i).rbx << " " << myHFFrontEnd.at(i).rm << " " << myHFFrontEnd.at(i).rm_fiber << " " << myHFFrontEnd.at(i).fiber_ch << " " << myHFFrontEnd.at(i).qie8 << " " << myHFFrontEnd.at(i).qie8_ch << " "
                //<< "HFBackEnd(ucrate,uhtr,uhtr_fiber,fiber_ch): " 
                << myHFBackEnd.at(i).ucrate << " " << myHFBackEnd.at(i).uhtr << " " << myHFBackEnd.at(i).uhtr_fiber << " " << myHFBackEnd.at(i).fiber_ch << " "
                << std::endl;
    }
    return ;
  }
}
*/
