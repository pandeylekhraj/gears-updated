{
    // constants
    double CE = 0.02; // light collection efficiency (https://arxiv.org/abs/1712.02011)
    double QE=0.3; // quantum efficiency of PMT
    double R=50; // 50 Ohm load resistor
    double e=1.6e-19; // charge of an electron [Coulomb]
    // https://eljentechnology.com/products/plastic-scintillators/ej-200-ej-204-ej-208-ej-212
    double LY=10; // light yield: 10 photons/keVee
    double dt=3e-9; // scintillation rise time + decay time ~ 3 ns

    TH1F hEg("hEg", ";Energy [keV];",100,0,31000);
    TH1F hEm("hEm", ";Energy [keV];",100,0,31000);
    TH1F hVg("hVg", ";Voltage [V];",100,0,510);
    TH1F hVm("hVm", ";Voltage [V];",100,0,510);

    hEg.SetLineColor(kRed);
    hEm.SetLineColor(kBlue);
    hVg.SetLineColor(kRed);
    hVm.SetLineColor(kBlue);

    TChain tg("t");
    tg.Add("g2614.root");
    tg.Draw("et[21]>>hEg"); // total energy deposition in top panel [keV]
    int ng=tg.GetSelectedRows();
    cout<<ng<<" gamma events in total"<<endl;
    double *eg=tg.GetV1();

    for (int i=0; i<ng; i++) {
        int nph=gRandom->Poisson(eg[i]*LY);
        int npe=gRandom->Poisson(nph*CE*QE);
        double ne=gRandom->Gaus(nph*1e6,sqrt(nph*1e6));
        double V=ne*e/dt*R;
        hVg.Fill(V);
    }

    TChain tm("t");
    tm.Add("mu+4GeV.root");
    tm.Draw("et[21]>>hEm"); // total energy deposition in top panel [keV]
    int nm=tm.GetSelectedRows();
    cout<<nm<<" muon events in total"<<endl;
    double *em=tm.GetV1();

    for (int i=0; i<nm; i++) {
        int nph=gRandom->Poisson(em[i]*LY);
        int npe=gRandom->Poisson(nph*CE*QE);
        double ne=gRandom->Gaus(nph*1e6,sqrt(nph*1e6));
        double V=ne*e/dt*R;
        hVm.Fill(V);
    }

    hEm.Draw();
    hEg.Draw("same");

    TLegend leg(0.7,0.5,0.9,0.65);
    leg.AddEntry(&hEg, "2.6 MeV #gamma", "l");
    leg.AddEntry(&hEm, "4 GeV #mu^{+}", "l");
    leg.Draw();

    TCanvas can;
    hVm.Draw();
    hVg.Draw("same");
    leg.Draw();
}
