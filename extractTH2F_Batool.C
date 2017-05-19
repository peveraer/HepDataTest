#if !defined(__CINT__) || defined(__MAKECINT__)
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TClonesArray.h>
#include <TString.h>
#include <TBenchmark.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <TFile.h>
#include <TH2F.h>
#include <TTree.h>
#include <TLorentzVector.h>
#include <TLegend.h>
#include <TCanvas.h>
#include <THStack.h>
#include <TProfile.h>
#include <TLatex.h>
#include <fstream>
#endif


void extractTH2F_Batool(string model){


  char filename[100];
  sprintf(filename,"%s_limits.root",model.c_str());
  TFile * limitFile=new TFile(filename);
  TH2* hobs = (TH2*)  limitFile->FindObjectAny("combined_obsLimit_BR100pct");


  char filename2[100];
  sprintf(filename2,"%s_2Dexclusion.yaml",model.c_str());
  std::ofstream output (filename2, std::ofstream::out);
  output<<" dependent_variables:"<<std::endl; 
  output<<"- header: '95% CL upper limit on cross section [pb]'} "<<std::endl;
  output<<" qualifiers:"<<std::endl;
  output<<"  - {name: RE, value: P P --> SBOTTOM SBOTTOM}"<<std::endl;
  output<<"  - {name: SQRT(S), units: GeV, value: '13000.0'}"<<std::endl;
  output<<"  - {name: '', value: 'Columns give stop mass, LSP mass and cross-section UL in pb.'}"<<std::endl;
  output<<"   values:"<<std::endl;
  for (int i=0;i<hobs->GetNbinsX();i++){
    for (int j=0;j<hobs->GetNbinsX();j++){
      if(hobs->GetBinContent(i+1,j+1)>0) output<<"  - {value: "<<hobs->GetBinContent(i+1,j+1)<<"}"<<std::endl;
    }
  }
  output<<" independent_variables:"<<std::endl;
  output<<"- header: 'M_{#tilde{t}} [GeV]'} "<<std::endl;
  output<<"   values:"<<std::endl;
  for (int i=0;i<hobs->GetNbinsX();i++){
    for (int j=0;j<hobs->GetNbinsX();j++){
      if(hobs->GetBinContent(i+1,j+1)>0) output<<"  - {value: "<<hobs->GetXaxis()->GetBinCenter(i+1)<<"}"<<std::endl;
    }
  }
  output<<"- header: 'M_{#tilde{#chi^{0}_{1}}} [GeV]'} "<<std::endl;
  output<<"   values:"<<std::endl;
  for (int i=0;i<hobs->GetNbinsX();i++){
    for (int j=0;j<hobs->GetNbinsX();j++){
      if(hobs->GetBinContent(i+1,j+1)>0) output<<"  - {value: "<<hobs->GetYaxis()->GetBinCenter(i+1)<<"}"<<std::endl;
    }
  }
}
