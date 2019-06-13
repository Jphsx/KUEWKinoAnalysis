
#include "plotTools.C"


void processCombineResult(){

	//open relevant root files

	std::string path = "/home/t3-ku/janguian/NTUPLES/CombinedNtuple/CombineResult.root";
	//testpath
//	std::string path = "~/work/research/susy/ewkinos/CombineResult.root";
	TFile *f = new TFile(path.c_str());

/////PLOTS FOR NON CATEGORICAL BKG AND SIGNAL

	///MET
	TH1D* DY17met =(TH1D*) f->Get("DY17Imet");
	TH1D* TTbar2017met =(TH1D*) f->Get("TT17Imet");
//	DY17met->Draw();
	TH1D* WJets2017met = (TH1D*) f->Get("W17Imet");
	TH1D* WW2017met = (TH1D*) f->Get("WW17Imet");
	TH1D* WZ2017met = (TH1D*) f->Get("WZ17Imet");
	std::vector<TH1D*> bkgmet{TTbar2017met, DY17met,WJets2017met, WW2017met, WZ2017met};
	std::vector<int> bkgcol{2,3,4,6,7};
	std::vector<int> bkgline{1,1,1,1,1};
	std::vector<std::string> bkglegdesc{ "TTbar","DY", "WJets","WW","WZ"};
	std::string bkghead = "";

	plotsuper(bkgmet, bkgcol, bkgline, bkglegdesc, bkghead, "bkgmet", "", 1);


	TH1D* TCWZ300met = (TH1D*) f->Get("TCWZ300Imet");
	TH1D* TCWZ30met = (TH1D*) f->Get("TCWZ30Imet");
	TH1D* TCWZ3met = (TH1D*) f->Get("TCWZ3Imet");
	std::vector<TH1D*> smet{ TCWZ30met, TCWZ300met, TCWZ3met };
	std::vector<int> scol{8, 9 , 1};
	std::vector<int> sline{1,1,1};
	std::vector<std::string> slegdesc{  "175_145", "600_300", "150_147" };
	std::string shead = "";

	plotsuper(smet, scol, sline, slegdesc, shead, "smet", "", 1);

	/// MLL
	TH1D* DY17mll =(TH1D*) f->Get("DY17Imll");
	TH1D* TTbar2017mll =(TH1D*) f->Get("TT17Imll");
	TH1D* WJets2017mll = (TH1D*) f->Get("W17Imll");
	TH1D* WW2017mll = (TH1D*) f->Get("WW17Imll");
	TH1D* WZ2017mll = (TH1D*) f->Get("WZ17Imll");
	std::vector<TH1D*> bkgmll{TTbar2017mll, DY17mll,WJets2017mll, WW2017mll, WZ2017mll};


	plotsuper(bkgmll, bkgcol, bkgline, bkglegdesc, bkghead, "bkgmll", "", 1);


	TH1D* TCWZ300mll = (TH1D*) f->Get("TCWZ300Imll");
	TH1D* TCWZ30mll = (TH1D*) f->Get("TCWZ30Imll");
	TH1D* TCWZ3mll = (TH1D*) f->Get("TCWZ3Imll");
	std::vector<TH1D*> smll{ TCWZ30mll, TCWZ300mll, TCWZ3mll };


	plotsuper(smll, scol, sline, slegdesc, shead, "smll", "", 1);


	///Njet
	TH1D* DY17njet =(TH1D*) f->Get("DY17Injet");
	TH1D* TTbar2017njet =(TH1D*) f->Get("TT17Injet");
	TH1D* WJets2017njet = (TH1D*) f->Get("W17Injet");
	TH1D* WW2017njet = (TH1D*) f->Get("WW17Injet");
	TH1D* WZ2017njet = (TH1D*) f->Get("WZ17Injet");
	std::vector<TH1D*> bkgnjet{TTbar2017njet, DY17njet, WJets2017njet, WW2017njet, WZ2017njet};


	plotsuper(bkgnjet, bkgcol, bkgline, bkglegdesc, bkghead, "bkgnjet", "", 1);


	TH1D* TCWZ300njet = (TH1D*) f->Get("TCWZ300Injet");
	TH1D* TCWZ30njet = (TH1D*) f->Get("TCWZ30Injet");
	TH1D* TCWZ3njet = (TH1D*) f->Get("TCWZ3Injet");
	std::vector<TH1D*> snjet{ TCWZ30njet, TCWZ300njet, TCWZ3njet };


	plotsuper(snjet, scol, sline, slegdesc, shead, "snjet", "", 1);



	///PTCM
	TH1D* DY17ptcm =(TH1D*) f->Get("DY17Iptcm");
	TH1D* TTbar2017ptcm =(TH1D*) f->Get("TT17Iptcm");
	TH1D* WJets2017ptcm = (TH1D*) f->Get("W17Iptcm");
	TH1D* WW2017ptcm = (TH1D*) f->Get("WW17Iptcm");
	TH1D* WZ2017ptcm = (TH1D*) f->Get("WZ17Iptcm");
	std::vector<TH1D*> bkgptcm{TTbar2017ptcm, DY17ptcm, WJets2017ptcm, WW2017ptcm, WZ2017ptcm};


	plotsuper(bkgptcm, bkgcol, bkgline, bkglegdesc, bkghead, "bkgptcm", "", 1);


	TH1D* TCWZ300ptcm = (TH1D*) f->Get("TCWZ300Iptcm");
	TH1D* TCWZ30ptcm = (TH1D*) f->Get("TCWZ30Iptcm");
	TH1D* TCWZ3ptcm = (TH1D*) f->Get("TCWZ3Iptcm");
	std::vector<TH1D*> sptcm{ TCWZ30ptcm, TCWZ300ptcm, TCWZ3ptcm };


	plotsuper(sptcm, scol, sline, slegdesc, shead, "sptcm", "", 1);

  ///////////////// END NOT CATEGORICAL

  /////////////STAR CATEGORICAL PTISR RISR ALL TYPES PER CHANNEL PLOTS


	std::vector<int> typecol{2, 3, 4};
	std::vector<int> typeline{1,1,1};
	std::vector<std::string> typelegdesc{  "Type I", "Type II", "Type III" };
	std::string typehead = "DY";

  std::string var1a = "DY17I";
  std::string varpt = "ptisr";
  std::string varr = "risr";

  std::vector<TH1D*> typeptisr(3);
  std::vector<TH1D*> typerisr(3);


  for(int i =0; i< 3; i++){
		typeptisr.at(i) = (TH1D*) f->Get((var1a+varpt).c_str());
		typerisr.at(i) = (TH1D*) f->Get((var1a+varr).c_str());
		var1a = var1a+"I";
  }

	plotsuper(typeptisr, typecol, typeline, typelegdesc, typehead, "typeptisr", "DY", 1);
	plotsuper(typerisr, typecol, typeline, typelegdesc, typehead, "typerisr", "DY", 1);


 std::string var1b = "TT17I";
 typehead = "TT";
  for(int i =0; i< 3; i++){
		typeptisr.at(i) = (TH1D*) f->Get((var1b+varpt).c_str());
		typerisr.at(i) = (TH1D*) f->Get((var1b+varr).c_str());
		var1b = var1b+"I";
  }

	plotsuper(typeptisr, typecol, typeline, typelegdesc, typehead, "typeptisr", "TT", 1);
	plotsuper(typerisr, typecol, typeline, typelegdesc, typehead, "typerisr", "TT", 1);


  std::string var1c = "TCWZ300I";
  typehead = "TCWZ300";
  for(int i =0; i< 3; i++){
		typeptisr.at(i) = (TH1D*) f->Get((var1c+varpt).c_str());
		typerisr.at(i) = (TH1D*) f->Get((var1c+varr).c_str());
		var1c = var1c+"I";
  }

	TH1D* temp = typerisr.at(2);
	typerisr.at(2) = typerisr.at(0);
	typerisr.at(0) = temp;
	std::vector<std::string> specdsc{"Type III", "TypeII", "Type I"};
	plotsuper(typeptisr, typecol, typeline, typelegdesc, typehead, "typeptisr", "TCWZ300", 1);
	plotsuper(typerisr, typecol, typeline, specdsc, typehead, "typerisr", "TCWZ300", 1);

 std::string var1d = "TCWZ30I";
 typehead = "TCWZ30";
  for(int i =0; i< 3; i++){
		typeptisr.at(i) = (TH1D*) f->Get((var1d+varpt).c_str());
		typerisr.at(i) = (TH1D*) f->Get((var1d+varr).c_str());
		var1d = var1d+"I";
  }

	plotsuper(typeptisr, typecol, typeline, typelegdesc, typehead, "typeptisr", "TCWZ30", 1);
	plotsuper(typerisr, typecol, typeline, typelegdesc, typehead, "typerisr", "TCWZ30", 1);

 ///////////////////////////// END PER CHANNEL

}
