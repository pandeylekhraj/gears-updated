{
	TChain tm100M("t");
	tm100M.Add("mu-100MeV.root");
	TH1F hm100M("hm100M",";Energy deposition of vertically "
			"down-going muons in top panel [MeV];",60,0,30);
	tm100M.Draw("et[21]/1000>>hm100M");

	TChain tm1GeV("t");
	tm1GeV.Add("mu-1GeV.root");
	TH1F hm1GeV("hm1GeV","",60,0,30);
	tm1GeV.Draw("et[21]/1000>>hm1GeV");

	TChain tm4GeV("t");
	tm4GeV.Add("mu-4GeV.root");
	TH1F hm4GeV("hm4GeV","",60,0,30);
	tm4GeV.Draw("et[21]/1000>>hm4GeV");

	TChain tm20GeV("t");
	tm20GeV.Add("mu-20GeV.root");
	TH1F hm20GeV("hm20GeV","",60,0,30);
	tm20GeV.Draw("et[21]/1000>>hm20GeV");

	TChain tp100M("t");
	tp100M.Add("mu+100MeV.root");
	TH1F hp100M("hp100M","",60,0,30);
	tp100M.Draw("et[21]/1000>>hp100M");

	TChain tp1GeV("t");
	tp1GeV.Add("mu+1GeV.root");
	TH1F hp1GeV("hp1GeV","",60,0,30);
	tp1GeV.Draw("et[21]/1000>>hp1GeV");

	TChain tp4GeV("t");
	tp4GeV.Add("mu+4GeV.root");
	TH1F hp4GeV("hp4GeV","",60,0,30);
	tp4GeV.Draw("et[21]/1000>>hp4GeV");

	TChain tp20GeV("t");
	tp20GeV.Add("mu+20GeV.root");
	TH1F hp20GeV("hp20GeV","",60,0,30);
	tp20GeV.Draw("et[21]/1000>>hp20GeV");

	hm100M.SetStats(0);

	hm100M.SetLineStyle(kDotted);
	hm1GeV.SetLineStyle(kDotted);
	hm4GeV.SetLineStyle(kDotted);
	hm20GeV.SetLineStyle(kDotted);

	hp1GeV.SetLineColor(kMagenta);
	hp4GeV.SetLineColor(kBlue);
	hp20GeV.SetLineColor(kGreen);

	hm1GeV.SetLineColor(kMagenta);
	hm4GeV.SetLineColor(kBlue);
	hm20GeV.SetLineColor(kGreen);

	hm100M.Draw();
	hm1GeV.Draw("same");
	hm4GeV.Draw("same");
	hm20GeV.Draw("same");

	hp100M.Draw("same");
	hp1GeV.Draw("same");
	hp4GeV.Draw("same");
	hp20GeV.Draw("same");

	TLegend leg(0.6,0.3,0.85,0.85);
	leg.AddEntry(&hp100M, "#mu^{+}, 100 MeV", "l");
	leg.AddEntry(&hp1GeV, "#mu^{+}, 1 GeV", "l");
	leg.AddEntry(&hp4GeV, "#mu^{+}, 4 GeV", "l");
	leg.AddEntry(&hp20GeV, "#mu^{+}, 20 GeV", "l");
	leg.AddEntry(&hm100M, "#mu^{-}, 100 MeV", "l");
	leg.AddEntry(&hm1GeV, "#mu^{-}, 1 GeV", "l");
	leg.AddEntry(&hm4GeV, "#mu^{-}, 4 GeV", "l");
	leg.AddEntry(&hm20GeV, "#mu^{-}, 20 GeV", "l");
	leg.Draw();

	TCanvas can; can.SetLogy();
	TH1F hs20GeV("hs20GeV",";Energy deposition of vertically "
			"down-going muons in panels [MeV];",60,0,30);
	tp20GeV.Draw("et[22]/1000>>hs20GeV");
	hs20GeV.SetStats(0);
	hp20GeV.Draw("same");

	TLegend legend(0.7,0.7,0.95, 0.9);
	legend.SetHeader("#mu^{+}, 20 GeV");
	legend.AddEntry(&hp20GeV, "Top panel", "l");
	legend.AddEntry(&hs20GeV, "Side panel", "l");
	legend.Draw();

	TCanvas c2; c2.SetLogy();
	TH1F hs20full("hs20full",";Energy deposition of vertically "
			"down-going muons in side panel [MeV];",72,0,720);
	tp20GeV.Draw("et[22]/1000>>hs20full");

	TCanvas c3; c3.SetLogy();
	TChain tm4side("t");
	tm4side.Add("mu-4GeVside.root");
	TH1F hm4side("hm4side",";Energy deposition of "
			"horizontal muons in panels [MeV];",60,0,30);
	TH1F hm4st("hm4st","",60,0,30);
	tm4side.Draw("et[25]/1000>>hm4side");
	tm4side.Draw("et[21]/1000>>hm4st");

	hm4side.SetLineColor(kRed);
	hm4st.SetLineColor(kGreen);
	hm4side.SetStats(0);
	hm4side.Draw();
	hm4st.Draw("same");

	TLegend le(0.7,0.7,0.95, 0.9);
	le.SetHeader("#mu^{-}, 4 GeV");
	le.AddEntry(&hm4side, "Side panel", "l");
	le.AddEntry(&hm4st, "Top panel", "l");
	le.Draw();

	TCanvas c4; c4.SetLogy();
	TChain tm4G45("t");
	tm4G45.Add("mu-4GeV45deg.root");
	TH1F hm4G45("hm4G45",";Energy deposition of "
			"45^{#circ} muons in panels [MeV];",100,0,50);
	TH1F hm45st("hm45st","",100,0,50);
	tm4G45.Draw("et[25]/1000>>hm4G45");
	tm4G45.Draw("et[21]/1000>>hm45st");

	hm4G45.SetLineColor(kRed);
	hm45st.SetLineColor(kGreen);
	hm4G45.SetStats(0);
	hm4G45.Draw();
	hm45st.Draw("same");

	TLegend lege(0.7,0.7,0.95, 0.9);
	lege.SetHeader("#mu^{-}, 4 GeV");
	lege.AddEntry(&hm4G45, "Side panel", "l");
	lege.AddEntry(&hm45st, "Top panel", "l");
	lege.Draw();
}
