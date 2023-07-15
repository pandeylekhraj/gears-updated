## Contents

- [NA.tg](NA.tg): geometry of COH-CryoCsI-1 in NA
- [shield.tg](shield.tg): geometry of PTR in shield
- [PTR.tg](PTR.tg): geometry of CsI in PTR
- [muon.mac](muon.mac): Geant4 macro for cosmic-ray muon simulation
- [rootlogon.C](rootlogon.C): configuration of [ROOT][] plots
- [docker-compose.yml](docker-compose.yml): docker-compose service definitions
- [drawEinMuonPanels.C](drawEinMuonPanels.C): draw energy distributions of cosmic-ray muons in scintillation panels
- [drawVinMuonPanels.C](drawVinMuonPanels.C): draw voltage distributions of cosmic-ray muons in scintillation panels

## Get started

Place this project side by side with <https://github.com/jintonic/gears> to use [physino/gears][].

```sh
git clone https://github.com/jintonic/gears.git
git clone https://github.com/jintonic/COH-CryoCsI-1.git
cd gears
docker-compose run --rm gears
root@Geant4:~/gears $ geant4-config --install-datasets
root@Geant4:~/gears $ exit
cd ../COH-CryoCsI-1
docker-compose run --rm gears
root@Geant4:~/COH-CryoCsI-1 $ ls
```

## NA
- Size of NA:
  - Height: 2.3 m
  - Width: 3 m
- Secondary confinement exhaust
  - 40" NPS (nominal pipe size), 1/4 304L

[ROOT]: https://root.cern.ch/
[physino/gears]: https://hub.docker.com/r/physino/gears
