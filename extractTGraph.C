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
#include <TGraph.h>
#include <TTree.h>
#include <TLorentzVector.h>
#include <TLegend.h>
#include <TCanvas.h>
#include <THStack.h>
#include <TProfile.h>
#include <TLatex.h>
#include <fstream>
#endif


void extractTGraph(string model){


  char filename[100];
  sprintf(filename,"%s_smooth.root",model.c_str());
  TFile * limitFile=new TFile(filename);
  TGraph* gExp = (TGraph*)  limitFile->FindObjectAny("gExp");
  TGraph* gExp1p = (TGraph*)  limitFile->FindObjectAny("gExp1p");
  TGraph* gExp1m = (TGraph*)  limitFile->FindObjectAny("gExp1m");
  TGraph* gObs = (TGraph*)  limitFile->FindObjectAny("gObs");
  TGraph* gObs1p = (TGraph*)  limitFile->FindObjectAny("gObs1p");
  TGraph* gObs1m = (TGraph*)  limitFile->FindObjectAny("gObs1m");


  char filenameExp[100];
  sprintf(filenameExp,"%s_Exp.yaml",model.c_str());
  std::ofstream outputExp (filenameExp, std::ofstream::out);
  outputExp<<" dependent_variables:"<<std::endl; 
  outputExp<<"- header: 'M_{#tilde{#chi^{0}_{1}}} [GeV]'} "<<std::endl;
  outputExp<<" qualifiers:"<<std::endl;
  outputExp<<"  - {name: RE, value: P P --> STOP STOP}"<<std::endl;
  outputExp<<"  - {name: SQRT(S), units: GeV, value: '13000.0'}"<<std::endl;
  outputExp<<"  - {name: '', value: 'Columns give stop mass and LSP mass of the expected exclusion'}"<<std::endl;
  outputExp<<"   values:"<<std::endl;
  for (int i=0;i<gExp->GetN();i++){
    outputExp<<"  - {value: "<<gExp->GetY()[i]<<"}"<<std::endl;
  }
  outputExp<<" independent_variables:"<<std::endl;
  outputExp<<"- header: 'M_{#tilde{t}} [GeV]'} "<<std::endl;
  outputExp<<"   values:"<<std::endl;
  for (int i=0;i<gExp->GetN();i++){
    outputExp<<"  - {value: "<<gExp->GetX()[i]<<"}"<<std::endl;
  }

 char filenameExp1p[100];
  sprintf(filenameExp1p,"%s_Exp1p.yaml",model.c_str());
  std::ofstream outputExp1p (filenameExp1p, std::ofstream::out);
  outputExp1p<<" dependent_variables:"<<std::endl; 
  outputExp1p<<"- header: 'M_{#tilde{#chi^{0}_{1}}} [GeV]'} "<<std::endl;
  outputExp1p<<" qualifiers:"<<std::endl;
  outputExp1p<<"  - {name: RE, value: P P --> STOP STOP}"<<std::endl;
  outputExp1p<<"  - {name: SQRT(S), units: GeV, value: '13000.0'}"<<std::endl;
  outputExp1p<<"  - {name: '', value: 'Columns give stop mass and LSP mass of the expected exclusion'}"<<std::endl;
  outputExp1p<<"   values:"<<std::endl;
  for (int i=0;i<gExp1p->GetN();i++){
    outputExp1p<<"  - {value: "<<gExp1p->GetY()[i]<<"}"<<std::endl;
  }
  outputExp1p<<" independent_variables:"<<std::endl;
  outputExp1p<<"- header: 'M_{#tilde{t}} [GeV]'} "<<std::endl;
  outputExp1p<<"   values:"<<std::endl;
  for (int i=0;i<gExp1p->GetN();i++){
    outputExp1p<<"  - {value: "<<gExp1p->GetX()[i]<<"}"<<std::endl;
  }

 char filenameExp1m[100];
  sprintf(filenameExp1m,"%s_Exp1m.yaml",model.c_str());
  std::ofstream outputExp1m (filenameExp1m, std::ofstream::out);
  outputExp1m<<" dependent_variables:"<<std::endl; 
  outputExp1m<<"- header: 'M_{#tilde{#chi^{0}_{1}}} [GeV]'} "<<std::endl;
  outputExp1m<<" qualifiers:"<<std::endl;
  outputExp1m<<"  - {name: RE, value: P P --> STOP STOP}"<<std::endl;
  outputExp1m<<"  - {name: SQRT(S), units: GeV, value: '13000.0'}"<<std::endl;
  outputExp1m<<"  - {name: '', value: 'Columns give stop mass and LSP mass of the expected exclusion'}"<<std::endl;
  outputExp1m<<"   values:"<<std::endl;
  for (int i=0;i<gExp1m->GetN();i++){
    outputExp1m<<"  - {value: "<<gExp1m->GetY()[i]<<"}"<<std::endl;
  }
  outputExp1m<<" independent_variables:"<<std::endl;
  outputExp1m<<"- header: 'M_{#tilde{t}} [GeV]'} "<<std::endl;
  outputExp1m<<"   values:"<<std::endl;
  for (int i=0;i<gExp1m->GetN();i++){
    outputExp1m<<"  - {value: "<<gExp1m->GetX()[i]<<"}"<<std::endl;
  }

  char filenameObs[100];
  sprintf(filenameObs,"%s_Obs.yaml",model.c_str());
  std::ofstream outputObs (filenameObs, std::ofstream::out);
  outputObs<<" dependent_variables:"<<std::endl; 
  outputObs<<"- header: 'M_{#tilde{#chi^{0}_{1}}} [GeV]'} "<<std::endl;
  outputObs<<" qualifiers:"<<std::endl;
  outputObs<<"  - {name: RE, value: P P --> STOP STOP}"<<std::endl;
  outputObs<<"  - {name: SQRT(S), units: GeV, value: '13000.0'}"<<std::endl;
  outputObs<<"  - {name: '', value: 'Columns give stop mass and LSP mass of the expected exclusion'}"<<std::endl;
  outputObs<<"   values:"<<std::endl;
  for (int i=0;i<gObs->GetN();i++){
    outputObs<<"  - {value: "<<gObs->GetY()[i]<<"}"<<std::endl;
  }
  outputObs<<" independent_variables:"<<std::endl;
  outputObs<<"- header: 'M_{#tilde{t}} [GeV]'} "<<std::endl;
  outputObs<<"   values:"<<std::endl;
  for (int i=0;i<gObs->GetN();i++){
    outputObs<<"  - {value: "<<gObs->GetX()[i]<<"}"<<std::endl;
  }

 char filenameObs1p[100];
  sprintf(filenameObs1p,"%s_Obs1p.yaml",model.c_str());
  std::ofstream outputObs1p (filenameObs1p, std::ofstream::out);
  outputObs1p<<" dependent_variables:"<<std::endl; 
  outputObs1p<<"- header: 'M_{#tilde{#chi^{0}_{1}}} [GeV]'} "<<std::endl;
  outputObs1p<<" qualifiers:"<<std::endl;
  outputObs1p<<"  - {name: RE, value: P P --> STOP STOP}"<<std::endl;
  outputObs1p<<"  - {name: SQRT(S), units: GeV, value: '13000.0'}"<<std::endl;
  outputObs1p<<"  - {name: '', value: 'Columns give stop mass and LSP mass of the expected exclusion'}"<<std::endl;
  outputObs1p<<"   values:"<<std::endl;
  for (int i=0;i<gObs1p->GetN();i++){
    outputObs1p<<"  - {value: "<<gObs1p->GetY()[i]<<"}"<<std::endl;
  }
  outputObs1p<<" independent_variables:"<<std::endl;
  outputObs1p<<"- header: 'M_{#tilde{t}} [GeV]'} "<<std::endl;
  outputObs1p<<"   values:"<<std::endl;
  for (int i=0;i<gObs1p->GetN();i++){
    outputObs1p<<"  - {value: "<<gObs1p->GetX()[i]<<"}"<<std::endl;
  }

 char filenameObs1m[100];
  sprintf(filenameObs1m,"%s_Obs1m.yaml",model.c_str());
  std::ofstream outputObs1m (filenameObs1m, std::ofstream::out);
  outputObs1m<<" dependent_variables:"<<std::endl; 
  outputObs1m<<"- header: 'M_{#tilde{#chi^{0}_{1}}} [GeV]'} "<<std::endl;
  outputObs1m<<" qualifiers:"<<std::endl;
  outputObs1m<<"  - {name: RE, value: P P --> STOP STOP}"<<std::endl;
  outputObs1m<<"  - {name: SQRT(S), units: GeV, value: '13000.0'}"<<std::endl;
  outputObs1m<<"  - {name: '', value: 'Columns give stop mass and LSP mass of the expected exclusion'}"<<std::endl;
  outputObs1m<<"   values:"<<std::endl;
  for (int i=0;i<gObs1m->GetN();i++){
    outputObs1m<<"  - {value: "<<gObs1m->GetY()[i]<<"}"<<std::endl;
  }
  outputObs1m<<" independent_variables:"<<std::endl;
  outputObs1m<<"- header: 'M_{#tilde{t}} [GeV]'} "<<std::endl;
  outputObs1m<<"   values:"<<std::endl;
  for (int i=0;i<gObs1m->GetN();i++){
    outputObs1m<<"  - {value: "<<gObs1m->GetX()[i]<<"}"<<std::endl;
  }

}
