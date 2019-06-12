import sys 
import os
import subprocess

def bash( bashCommand ):
	process = subprocess.Popen(bashCommand.split(), stdout=subprocess.PIPE)
	#process = subprocess.Popen(bashCommand.split())
	output, error = process.communicate()
	return output ,error

DYDir=['DYJetsToLL_M-4to50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'DYJetsToLL_M-4to50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'DYJetsToLL_M-4to50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'DYJetsToLL_M-4to50_HT-600toInf_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17']

TTDir=['TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8_Fall17',
'TTToHadronic_TuneCP5_13TeV-powheg-pythia8_Fall17',
'TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_Fall17']

WJetsDir=['WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'WJetsToQQ_HT-800toInf_qc19_3j_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'WJetsToQQ_HT400to600_qc19_3j_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17',
'WJetsToQQ_HT600to800_qc19_3j_TuneCP5_13TeV-madgraphMLM-pythia8_Fall17']

WWDir=['WW_TuneCP5_13TeV-pythia8_Fall17']

WZDir=['WZ_TuneCP5_13TeV-pythia8_Fall17']

TChiWZDir=['SMS-TChiWZ_ZToLL_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_TuneCUETP']

PathToBkgProcessingDir='/home/t3-ku/crogan/NTUPLES/Processing/All_Bkg_2017/'
PathToSigProcessingDir='/home/t3-ku/crogan/NTUPLES/Processing/All_Sig/'


PathToLocalSigSkims='/home/t3-ku/janguian/NTUPLES/LocalSkims/Bkg_2017/'
PathToLocalBkgSkims='/home/t3-ku/janguian/NTUPLES/LocalSkims/Sig_2017/'

#print DYDir
#print TTDir
#print WJetsDir
#print WWDir
#print WZDir
#print TChiWZDir

BkgDirs= [DYDir, TTDir, WJetsDir, WWDir, WZDir]
SigDirs= [TChiWZDir]

#go to each directory and ls, the ls will contain all filenames, hadd all files into a file which is the directory name + .root
for dirlist in BkgDirs:
	for idir in dirlist:
		cmd = "ls "+PathToBkgProcessingDir+idir
		LS = bash(cmd)
		LS = bash(cmd)
		LS = LS[0].split('\n')
		LS = [f for f in LS if ".root" in f]
		cmd = "hadd -f "+PathToLocalBkgSkims+idir+".root"
		for ifile in LS:
			cmd = cmd + " "+PathToBkgProcesingDir+idir+ifile.rstrip()
		print cmd
		os.system(cmd)


