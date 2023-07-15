{
	TChain t1("t");
	t1.Add("n1MeVinTunnel.root");
	t1.Draw("k>>h12","pdg==2112 && vlm==2");
	TH1F *h12 = (TH1F*) gDirectory->Get("h12");

	t1.Draw("k>>h13","pdg==2112 && vlm==3");
	TH1F *h13 = (TH1F*) gDirectory->Get("h13");

	t1.Draw("k>>h14","pdg==2112 && vlm==4");
	TH1F *h14 = (TH1F*) gDirectory->Get("h14");

	h13->SetLineColor(kRed);
	h14->SetLineColor(kBlue);

	gPad->SetLogy();
	h12->Draw();
	h12->SetStats(0);
	h12->GetYaxis()->SetRangeUser(1,1e4);
	h12->GetXaxis()->SetTitle("Kinetic energy of neutrons in detector [keV]");
	h13->Draw("same");
	h14->Draw("same");

	TLegend le(0.3,0.5,0.6,0.88);
	le.SetHeader("1 MeV neutrons");
	le.AddEntry(h12, "detector 2", "l");
	le.AddEntry(h13, "detector 3", "l");
	le.AddEntry(h14, "detector 4", "l");
	le.Draw();

	TChain t10("t");
	t10.Add("n10MeVinTunnel.root");
	t10.Draw("k>>h104","pdg==2112 && vlm==4","goff");
	TH1F *h104 = (TH1F*) gDirectory->Get("h104");

	TChain t100("t");
	t100.Add("n100MeVinTunnel.root");
	t100.Draw("k>>h1004","pdg==2112 && vlm==4 && k<10000","goff");
	TH1F *h1004 = (TH1F*) gDirectory->Get("h1004");

	h104->SetLineColor(kRed);
	h1004->SetLineColor(kGreen);
	TH1F *h14c = (TH1F*) h14->Clone("h14c");
	h14c->Rebin(5);

	TCanvas can;
	can.SetLogy();
	h1004->Draw();
	h1004->SetStats(0);
	h1004->GetXaxis()->SetTitle("Kinetic energy of neutrons [keV]");
	h104->Draw("same");
	h14c->Draw("same");

	TLegend leg(0.7,0.5,0.95,0.88);
	leg.SetHeader("Detector 4");
	leg.AddEntry(h14, "1 MeV n", "l");
	leg.AddEntry(h104, "10 MeV n", "l");
	leg.AddEntry(h1004, "100 MeV n", "l");
	leg.Draw();
}
