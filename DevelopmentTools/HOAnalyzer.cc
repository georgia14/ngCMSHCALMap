#include "HOAnalyzer.h"

void HOAnalyzer::HONChannelBasicCheck()
{
  std::cout << "How many Channels do we have in HO ? " << NchHO_all << std::endl;
  std::cout << "Re-calculate from Front End: " << (NrbxHO0*NrmHO0 + NrbxHO12*NrmHO12) * Nrm_fiber * Nfiber_ch << std::endl;
  std::cout << "Re-calculate from Back End: " << Ncrate * Nhtr * Nfpga * Nhtr_fiber * Nfiber_ch + NspecialHOX << std::endl;
  std::cout << "Re-calculate from Geometry: " << NHOside * NHOeta * NHOphi * NHOdepth + NnormalHOX + NspecialHOX << std::endl;

  return ;
}

void HOAnalyzer::PlottingHOFEtoGeo(
                                   std::vector<HOFrontEnd> myHOFrontEnd,
                                   std::vector<HOGeometry> myHOGeometry
                                  )
{
  const std::string titre="CMS HCAL Channel Mapping";
  TLatex *title = new TLatex(0.09770115,0.9194915,titre.c_str());
  title->SetNDC(); title->SetTextSize(0.045);

  TCanvas *c = new TCanvas("c", "",0,51,3000,5000);
  c->Divide(2,5); c->SetFillColor(0); c->cd();

  TH2D *ho0rbxphi = new TH2D("ho0rbxphi", "Phi in HO0 FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO0*NrmHO0, 1, NrbxHO0*NrmHO0+1);
  TH2D *ho0rbxeta = new TH2D("ho0rbxeta", "Eta in HO0 FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO0*NrmHO0, 1, NrbxHO0*NrmHO0+1);
  TH2D *ho1prbxphi = new TH2D("ho1prbxphi", "Phi in HO1P FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho1prbxeta = new TH2D("ho1prbxeta", "Eta in HO1P FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho2prbxphi = new TH2D("ho2prbxphi", "Phi in HO2P FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho2prbxeta = new TH2D("ho2prbxeta", "Eta in HO2P FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho1mrbxphi = new TH2D("ho1mrbxphi", "Phi in HO1M FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho1mrbxeta = new TH2D("ho1mrbxeta", "Eta in HO1M FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho2mrbxphi = new TH2D("ho2mrbxphi", "Phi in HO2M FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho2mrbxeta = new TH2D("ho2mrbxeta", "Eta in HO2M FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);

  for(auto i=0; i<NchHO_all; i++)
  {
    std::string thisrbx = (myHOFrontEnd.at(i)).rbx;
    //std::cout << thisrbx << std::endl;
    //std::cout << (myHOGeometry.at(i)).eta << std::endl;
    //if( (myHOGeometry.at(i)).subdet != "HO") continue;    
    double zphi = (myHOGeometry.at(i)).phi;
    double zeta = (myHOGeometry.at(i)).side * (myHOGeometry.at(i)).eta;
    double x = ((myHOFrontEnd.at(i)).rm_fiber-2)*3 + (myHOFrontEnd.at(i)).fiber_ch + 1;
    double rbxid = std::stod( thisrbx.substr( thisrbx.length() - 2 ) );//1,....12 for HO0, 2,4,6,8,10,12 for other HO12

    if( thisrbx.find("HO0") != std::string::npos )
    {
      double rmid = -1;//123,234 to 123
      if( rbxid == 1 || rbxid == 4 || rbxid == 5 || rbxid == 8 || rbxid == 9 || rbxid == 12 ) rmid = (myHOFrontEnd.at(i)).rm;
      else rmid = (myHOFrontEnd.at(i)).rm-1;
      double y = (rbxid-1)*3 + rmid;
      //std::cout << x << "," << y << std::endl;
      ho0rbxphi->Fill(x,y,zphi); ho0rbxeta->Fill(x,y,zeta);
    }
    else
    {
      double rmid = (myHOFrontEnd.at(i)).rm;//1234 to 1234
      double y = (rbxid/2-1)*4 + rmid;

      if( thisrbx.find("HO1P") != std::string::npos )
      {
        ho1prbxphi->Fill(x,y,zphi); ho1prbxeta->Fill(x,y,zeta);
      }
      else if( thisrbx.find("HO2P") != std::string::npos )
      {
        ho2prbxphi->Fill(x,y,zphi); ho2prbxeta->Fill(x,y,zeta);
      }
      else if( thisrbx.find("HO1M") != std::string::npos )
      {
        ho1mrbxphi->Fill(x,y,zphi); ho1mrbxeta->Fill(x,y,zeta);
      }
      else if( thisrbx.find("HO2M") != std::string::npos )
      {
        ho2mrbxphi->Fill(x,y,zphi); ho2mrbxeta->Fill(x,y,zeta);
      }
    }
  }

  for(int i=1;i<=Nrm_fiber*Nfiber_ch;i++)
  { 
    ho0rbxphi->GetXaxis()->SetBinLabel(i,HO0RMfiberlabel[i-1]); ho0rbxeta->GetXaxis()->SetBinLabel(i,HO0RMfiberlabel[i-1]); 
    ho1prbxphi->GetXaxis()->SetBinLabel(i,HO1RMfiberlabel[i-1]); ho1prbxeta->GetXaxis()->SetBinLabel(i,HO1RMfiberlabel[i-1]);
    ho2prbxphi->GetXaxis()->SetBinLabel(i,HO2RMfiberlabel[i-1]); ho2prbxeta->GetXaxis()->SetBinLabel(i,HO2RMfiberlabel[i-1]);
    ho1mrbxphi->GetXaxis()->SetBinLabel(i,HO1RMfiberlabel[i-1]); ho1mrbxeta->GetXaxis()->SetBinLabel(i,HO1RMfiberlabel[i-1]);
    ho2mrbxphi->GetXaxis()->SetBinLabel(i,HO2RMfiberlabel[i-1]); ho2mrbxeta->GetXaxis()->SetBinLabel(i,HO2RMfiberlabel[i-1]);
  }
  for(int i=1;i<=NrbxHO0*NrmHO0;i++) 
  { 
    ho0rbxphi->GetYaxis()->SetBinLabel(i,HO0RBXlabel[i-1]); ho0rbxeta->GetYaxis()->SetBinLabel(i,HO0RBXlabel[i-1]); 
  }
  for(int i=1;i<=NrbxHO12*NrmHO12/4;i++)
  {
    ho1prbxphi->GetYaxis()->SetBinLabel(i,HO1PRBXlabel[i-1]); ho1prbxeta->GetYaxis()->SetBinLabel(i,HO1PRBXlabel[i-1]);
    ho2prbxphi->GetYaxis()->SetBinLabel(i,HO2PRBXlabel[i-1]); ho2prbxeta->GetYaxis()->SetBinLabel(i,HO2PRBXlabel[i-1]);
    ho1mrbxphi->GetYaxis()->SetBinLabel(i,HO1MRBXlabel[i-1]); ho1mrbxeta->GetYaxis()->SetBinLabel(i,HO1MRBXlabel[i-1]);
    ho2mrbxphi->GetYaxis()->SetBinLabel(i,HO2MRBXlabel[i-1]); ho2mrbxeta->GetYaxis()->SetBinLabel(i,HO2MRBXlabel[i-1]);
  }

  //ho1prbxeta->SetXTitle(""); ho1prbxeta->SetYTitle("");
  ho0rbxphi->SetStats(0); ho0rbxeta->SetStats(0);
  ho1prbxphi->SetStats(0); ho1prbxeta->SetStats(0);
  ho2prbxphi->SetStats(0); ho2prbxeta->SetStats(0);
  ho1mrbxphi->SetStats(0); ho1mrbxeta->SetStats(0);
  ho2mrbxphi->SetStats(0); ho2mrbxeta->SetStats(0);

  c->cd(1); ho0rbxphi->Draw("colztext"); c->cd(2); ho0rbxeta->Draw("colztext");
  c->cd(3); ho1prbxphi->Draw("colztext"); c->cd(4); ho1prbxeta->Draw("colztext");
  c->cd(5); ho2prbxphi->Draw("colztext"); c->cd(6); ho2prbxeta->Draw("colztext");
  c->cd(7); ho1mrbxphi->Draw("colztext"); c->cd(8); ho1mrbxeta->Draw("colztext");
  c->cd(9); ho2mrbxphi->Draw("colztext"); c->cd(10); ho2mrbxeta->Draw("colztext");

  //title->Draw("same");

  c->SaveAs( (dir+"_HOFEetaphi.png").c_str() );
  c->SaveAs( (dir+"_HOFEetaphi.pdf").c_str() );
  c->SaveAs( (dir+"_HOFEetaphi.C").c_str() );
  c->Close();

  return ;
}

void HOAnalyzer::PlottingHOFEtoBEVME(
                                     std::vector<HOFrontEnd> myHOFrontEnd,
                                     std::vector<HOBackEnd> myHOBackEnd
                                    )
{
  TCanvas *c = new TCanvas("c", "",0,51,6000,5000);
  c->Divide(4,5); c->SetFillColor(0); c->cd();

  TH2D *ho0rbxcrate = new TH2D("ho0rbxcrate", "Crate in HO0 FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO0*NrmHO0, 1, NrbxHO0*NrmHO0+1);
  TH2D *ho0rbxhtr = new TH2D("ho0rbxhtr", "HTR in HO0 FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO0*NrmHO0, 1, NrbxHO0*NrmHO0+1);
  TH2D *ho0rbxfpga = new TH2D("ho0rbxfpga", "FPGA in HO0 FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO0*NrmHO0, 1, NrbxHO0*NrmHO0+1);
  TH2D *ho0rbxhtr_fiber = new TH2D("ho0rbxhtr_fiber", "HTRfiber in HO0 FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO0*NrmHO0, 1, NrbxHO0*NrmHO0+1);
  TH2D *ho1prbxcrate = new TH2D("ho1prbxcrate", "Crate in HO1P FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho1prbxhtr = new TH2D("ho1prbxhtr", "HTR in HO1P FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho1prbxfpga = new TH2D("ho1prbxfpga", "FPGA in HO1P FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho1prbxhtr_fiber = new TH2D("ho1prbxhtr_fiber", "HTRfiber in HO1P FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho2prbxcrate = new TH2D("ho2prbxcrate", "Crate in HO2P FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho2prbxhtr = new TH2D("ho2prbxhtr", "HTR in HO2P FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho2prbxfpga = new TH2D("ho2prbxfpga", "FPGA in HO2P FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho2prbxhtr_fiber = new TH2D("ho2prbxhtr_fiber", "HTRfiber in HO2P FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho1mrbxcrate = new TH2D("ho1mrbxcrate", "Crate in HO1M FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho1mrbxhtr = new TH2D("ho1mrbxhtr", "HTR in HO1M FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho1mrbxfpga = new TH2D("ho1mrbxfpga", "FPGA in HO1M FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho1mrbxhtr_fiber = new TH2D("ho1mrbxhtr_fiber", "HTRfiber in HO1M FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho2mrbxcrate = new TH2D("ho2mrbxcrate", "Crate in HO2M FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho2mrbxhtr = new TH2D("ho2mrbxhtr", "HTR in HO2M FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho2mrbxfpga = new TH2D("ho2mrbxfpga", "FPGA in HO2M FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);
  TH2D *ho2mrbxhtr_fiber = new TH2D("ho2mrbxhtr_fiber", "HTRfiber in HO2M FrontEnd", Nrm_fiber*Nfiber_ch, 1, Nrm_fiber*Nfiber_ch+1, NrbxHO12*NrmHO12/4, 1, NrbxHO12*NrmHO12/4+1);

  for(auto i=0; i<NchHO_all; i++)
  {
    std::string thisrbx = (myHOFrontEnd.at(i)).rbx;
    //std::cout << thisrbx << std::endl;
    double zcrate = (myHOBackEnd.at(i)).crate;
    double zhtr = (myHOBackEnd.at(i)).htr;
    double zfpga = 2000;
    ((myHOBackEnd.at(i)).fpga)=="top" ? zfpga = 1 : zfpga = -1;
    double zhtr_fiber = (myHOBackEnd.at(i)).htr_fiber;

    double x = ((myHOFrontEnd.at(i)).rm_fiber-2)*3 + (myHOFrontEnd.at(i)).fiber_ch + 1;
    double rbxid = std::stod( thisrbx.substr( thisrbx.length() - 2 ) );//1,....12 for HO0, 2,4,6,8,10,12 for other HO12

    if( thisrbx.find("HO0") != std::string::npos )
    {
      double rmid = -1;//123,234 to 123
      if( rbxid == 1 || rbxid == 4 || rbxid == 5 || rbxid == 8 || rbxid == 9 || rbxid == 12 ) rmid = (myHOFrontEnd.at(i)).rm;
      else rmid = (myHOFrontEnd.at(i)).rm-1;
      double y = (rbxid-1)*3 + rmid;
      //std::cout << x << "," << y << std::endl;
      ho0rbxcrate->Fill(x,y,zcrate); ho0rbxhtr->Fill(x,y,zhtr); ho0rbxfpga->Fill(x,y,zfpga); ho0rbxhtr_fiber->Fill(x,y,zhtr_fiber);
    }
    else
    {
      double rmid = (myHOFrontEnd.at(i)).rm;//1234 to 1234
      double y = (rbxid/2-1)*4 + rmid;

      if( thisrbx.find("HO1P") != std::string::npos )
      {
        ho1prbxcrate->Fill(x,y,zcrate); ho1prbxhtr->Fill(x,y,zhtr); ho1prbxfpga->Fill(x,y,zfpga); ho1prbxhtr_fiber->Fill(x,y,zhtr_fiber);
      }
      else if( thisrbx.find("HO2P") != std::string::npos )
      {
        ho2prbxcrate->Fill(x,y,zcrate); ho2prbxhtr->Fill(x,y,zhtr); ho2prbxfpga->Fill(x,y,zfpga); ho2prbxhtr_fiber->Fill(x,y,zhtr_fiber);
      }
      else if( thisrbx.find("HO1M") != std::string::npos )
      {
        ho1mrbxcrate->Fill(x,y,zcrate); ho1mrbxhtr->Fill(x,y,zhtr); ho1mrbxfpga->Fill(x,y,zfpga); ho1mrbxhtr_fiber->Fill(x,y,zhtr_fiber);
      }
      else if( thisrbx.find("HO2M") != std::string::npos )
      {
        ho2mrbxcrate->Fill(x,y,zcrate); ho2mrbxhtr->Fill(x,y,zhtr); ho2mrbxfpga->Fill(x,y,zfpga); ho2mrbxhtr_fiber->Fill(x,y,zhtr_fiber);
      }
    }
  }

  for(int i=1;i<=Nrm_fiber*Nfiber_ch;i++)
  { 
    ho0rbxcrate->GetXaxis()->SetBinLabel(i,HO0RMfiberlabel[i-1]); ho0rbxhtr->GetXaxis()->SetBinLabel(i,HO0RMfiberlabel[i-1]); 
    ho0rbxfpga->GetXaxis()->SetBinLabel(i,HO0RMfiberlabel[i-1]); ho0rbxhtr_fiber->GetXaxis()->SetBinLabel(i,HO0RMfiberlabel[i-1]);

    ho1prbxcrate->GetXaxis()->SetBinLabel(i,HO1RMfiberlabel[i-1]); ho1prbxhtr->GetXaxis()->SetBinLabel(i,HO1RMfiberlabel[i-1]);
    ho1prbxfpga->GetXaxis()->SetBinLabel(i,HO1RMfiberlabel[i-1]); ho1prbxhtr_fiber->GetXaxis()->SetBinLabel(i,HO1RMfiberlabel[i-1]);

    ho2prbxcrate->GetXaxis()->SetBinLabel(i,HO2RMfiberlabel[i-1]); ho2prbxhtr->GetXaxis()->SetBinLabel(i,HO2RMfiberlabel[i-1]);
    ho2prbxfpga->GetXaxis()->SetBinLabel(i,HO2RMfiberlabel[i-1]); ho2prbxhtr_fiber->GetXaxis()->SetBinLabel(i,HO2RMfiberlabel[i-1]);

    ho1mrbxcrate->GetXaxis()->SetBinLabel(i,HO1RMfiberlabel[i-1]); ho1mrbxhtr->GetXaxis()->SetBinLabel(i,HO1RMfiberlabel[i-1]);
    ho1mrbxfpga->GetXaxis()->SetBinLabel(i,HO1RMfiberlabel[i-1]); ho1mrbxhtr_fiber->GetXaxis()->SetBinLabel(i,HO1RMfiberlabel[i-1]);

    ho2mrbxcrate->GetXaxis()->SetBinLabel(i,HO2RMfiberlabel[i-1]); ho2mrbxhtr->GetXaxis()->SetBinLabel(i,HO2RMfiberlabel[i-1]);
    ho2mrbxfpga->GetXaxis()->SetBinLabel(i,HO2RMfiberlabel[i-1]); ho2mrbxhtr_fiber->GetXaxis()->SetBinLabel(i,HO2RMfiberlabel[i-1]);
  }
  for(int i=1;i<=NrbxHO0*NrmHO0;i++) 
  { 
    ho0rbxcrate->GetYaxis()->SetBinLabel(i,HO0RBXlabel[i-1]); ho0rbxhtr->GetYaxis()->SetBinLabel(i,HO0RBXlabel[i-1]); 
    ho0rbxfpga->GetYaxis()->SetBinLabel(i,HO0RBXlabel[i-1]); ho0rbxhtr_fiber->GetYaxis()->SetBinLabel(i,HO0RBXlabel[i-1]);
  }
  for(int i=1;i<=NrbxHO12*NrmHO12/4;i++)
  {
    ho1prbxcrate->GetYaxis()->SetBinLabel(i,HO1PRBXlabel[i-1]); ho1prbxhtr->GetYaxis()->SetBinLabel(i,HO1PRBXlabel[i-1]);
    ho1prbxfpga->GetYaxis()->SetBinLabel(i,HO1PRBXlabel[i-1]); ho1prbxhtr_fiber->GetYaxis()->SetBinLabel(i,HO1PRBXlabel[i-1]);

    ho2prbxcrate->GetYaxis()->SetBinLabel(i,HO2PRBXlabel[i-1]); ho2prbxhtr->GetYaxis()->SetBinLabel(i,HO2PRBXlabel[i-1]);
    ho2prbxfpga->GetYaxis()->SetBinLabel(i,HO2PRBXlabel[i-1]); ho2prbxhtr_fiber->GetYaxis()->SetBinLabel(i,HO2PRBXlabel[i-1]);

    ho1mrbxcrate->GetYaxis()->SetBinLabel(i,HO1MRBXlabel[i-1]); ho1mrbxhtr->GetYaxis()->SetBinLabel(i,HO1MRBXlabel[i-1]);
    ho1mrbxfpga->GetYaxis()->SetBinLabel(i,HO1MRBXlabel[i-1]); ho1mrbxhtr_fiber->GetYaxis()->SetBinLabel(i,HO1MRBXlabel[i-1]);

    ho2mrbxcrate->GetYaxis()->SetBinLabel(i,HO2MRBXlabel[i-1]); ho2mrbxhtr->GetYaxis()->SetBinLabel(i,HO2MRBXlabel[i-1]);
    ho2mrbxfpga->GetYaxis()->SetBinLabel(i,HO2MRBXlabel[i-1]); ho2mrbxhtr_fiber->GetYaxis()->SetBinLabel(i,HO2MRBXlabel[i-1]);
  }

  ho0rbxcrate->SetStats(0); ho0rbxhtr->SetStats(0); ho0rbxfpga->SetStats(0); ho0rbxhtr_fiber->SetStats(0);
  ho1prbxcrate->SetStats(0); ho1prbxhtr->SetStats(0); ho1prbxfpga->SetStats(0); ho1prbxhtr_fiber->SetStats(0);
  ho2prbxcrate->SetStats(0); ho2prbxhtr->SetStats(0); ho2prbxfpga->SetStats(0); ho2prbxhtr_fiber->SetStats(0);
  ho1mrbxcrate->SetStats(0); ho1mrbxhtr->SetStats(0); ho1mrbxfpga->SetStats(0); ho1mrbxhtr_fiber->SetStats(0);
  ho2mrbxcrate->SetStats(0); ho2mrbxhtr->SetStats(0); ho2mrbxfpga->SetStats(0); ho2mrbxhtr_fiber->SetStats(0);

  c->cd(1); ho0rbxcrate->Draw("colztext"); c->cd(2); ho0rbxhtr->Draw("colztext"); c->cd(3); ho0rbxfpga->Draw("colztext"); c->cd(4); ho0rbxhtr_fiber->Draw("colztext");
  c->cd(5); ho1prbxcrate->Draw("colztext"); c->cd(6); ho1prbxhtr->Draw("colztext"); c->cd(7); ho1prbxfpga->Draw("colztext"); c->cd(8); ho1prbxhtr_fiber->Draw("colztext");
  c->cd(9); ho2prbxcrate->Draw("colztext"); c->cd(10); ho2prbxhtr->Draw("colztext"); c->cd(11); ho2prbxfpga->Draw("colztext"); c->cd(12); ho2prbxhtr_fiber->Draw("colztext");
  c->cd(13); ho1mrbxcrate->Draw("colztext"); c->cd(14); ho1mrbxhtr->Draw("colztext"); c->cd(15); ho1mrbxfpga->Draw("colztext"); c->cd(16); ho1mrbxhtr_fiber->Draw("colztext");
  c->cd(17); ho2mrbxcrate->Draw("colztext"); c->cd(18); ho2mrbxhtr->Draw("colztext"); c->cd(19); ho2mrbxfpga->Draw("colztext"); c->cd(20); ho2mrbxhtr_fiber->Draw("colztext");

  c->SaveAs( (dir+"_HOFEcratehtrfpgahtr_fiber.png").c_str() );
  c->SaveAs( (dir+"_HOFEcratehtrfpgahtr_fiber.pdf").c_str() );
  c->SaveAs( (dir+"_HOFEcratehtrfpgahtr_fiber.C").c_str() );
  c->Close();

  return ;
}
