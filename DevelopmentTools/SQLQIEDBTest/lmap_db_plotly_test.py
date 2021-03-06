import sys
import sqlite3
import plotly.plotly as plt
import plotly.figure_factory as ff
#from plotly.offline import download_plotlyjs, init_notebook_mode, plot, iplot

def ValidationPlot_HBHE_FEC(subdet,var):
  conn = sqlite3.connect('../officialMap/HCALLogicalMap.db')
  c = conn.cursor()
  print "Opened database successfully";

  xlist = []
  ylist = []
  zlist = []

  rbx_hbp = ['HBP01','HBP02','HBP03','HBP04','HBP05','HBP06','HBP07','HBP08','HBP09','HBP10','HBP11','HBP12','HBP13','HBP14','HBP15','HBP16','HBP17','HBP18']
  rbx_hbm = ['HBM01','HBM02','HBM03','HBM04','HBM05','HBM06','HBM07','HBM08','HBM09','HBM10','HBM11','HBM12','HBM13','HBM14','HBM15','HBM16','HBM17','HBM18']
  rbx_hep = ['HEP01','HEP02','HEP03','HEP04','HEP05','HEP06','HEP07','HEP08','HEP09','HEP10','HEP11','HEP12','HEP13','HEP14','HEP15','HEP16','HEP17','HEP18']
  rbx_hem = ['HEM01','HEM02','HEM03','HEM04','HEM05','HEM06','HEM07','HEM08','HEM09','HEM10','HEM11','HEM12','HEM13','HEM14','HEM15','HEM16','HEM17','HEM18']

  if subdet in ('HBP','ngHBP'):
    rbx=rbx_hbp
  elif subdet in ('HBM','ngHBM'):
    rbx=rbx_hbm
  elif subdet in ('ngHEP'):
    rbx=rbx_hep
  elif subdet in ('ngHEM'):
    rbx=rbx_hem
  
  rm =[1,2,3,4]

  for thisrbx in rbx:
    for thisrm in rm:
      ylist.append(thisrbx+'RM'+str(thisrm))
      if subdet in ('HBP','HBM'):
        cursor = c.execute("SELECT RBX, RM, RM_FI, FI_CH, Crate, uHTR, uHTR_FI, Side, Eta, Phi, Depth from HBLogicalMap where RBX=? AND RM=? ORDER BY RM_FI,FI_CH", (thisrbx,thisrm))
      elif subdet in ('ngHBP','ngHBM'):
        cursor = c.execute("SELECT ngRBX, RM, RM_FI, FI_CH, Crate, uHTR, uHTR_FI, Side, Eta, Phi, Depth from ngHBLogicalMap where ngRBX=? AND RM=? ORDER BY RM_FI,FI_CH", (thisrbx,thisrm))
      elif subdet in ('ngHEP','ngHEM'):
        cursor = c.execute("SELECT ngRBX, RM, RM_FI, FI_CH, Crate, uHTR, uHTR_FI, Side, Eta, Phi, Depth from ngHELogicalMap where ngRBX=? AND RM=? ORDER BY RM_FI,FI_CH", (thisrbx,thisrm))

      zlistrbxrm=[]
      for row in cursor:
        if(len(ylist)==1):
          xlist.append('RMFI'+str(row[2])+'FICH'+str(row[3]))
        
        if var=='Crate':
          zlistrbxrm.append(row[4])
        elif var=='uHTR':
          zlistrbxrm.append(row[5])
        elif var=='uHTR_FI':
          zlistrbxrm.append(row[6])
        elif var=='Eta': 
          zlistrbxrm.append(row[7]*row[8])
        elif var=='Phi':
          zlistrbxrm.append(row[9])
        elif var=='Depth': 
          zlistrbxrm.append(row[10])
      zlist.append(zlistrbxrm)
  print "Operation done successfully";
  conn.close()

  #fig = ff.create_annotated_heatmap(zlist, x=xlist, y=ylist, annotation_text=z_text, colorscale='Viridis')
  fig = ff.create_annotated_heatmap(zlist, x=xlist, y=ylist, colorscale='Viridis')
  fig['layout']['xaxis'].update(side='bottom')
  fig['layout'].update(height=1500, width=1500, title=subdet+' '+var+' in FrontEnd coordiantes')
  plt.plot(fig, filename=subdet+'_'+var+'_in_FrontEnd')
  #plotly.offline.plot(fig, filename=subdet+'_'+var+'_in_FrontEnd')

def ValidationPlot_HF_FEC(subdet,var):
  conn = sqlite3.connect('../officialMap/HCALLogicalMap.db')
  c = conn.cursor()
  print "Opened database successfully";

  xlist = []
  ylist = []
  zlist = []

  rbx_hfp = ['HFP01','HFP02','HFP03','HFP04','HFP05','HFP06','HFP07','HFP08']
  rbx_hfm = ['HFM01','HFM02','HFM03','HFM04','HFM05','HFM06','HFM07','HFM08']

  if subdet in ('ngHFP'):
    rbx=rbx_hfp
  elif subdet in ('ngHFM'):
    rbx=rbx_hfm
  
  qie =[3,4,5,6,10,11,12,13,14]

  for thisrbx in rbx:
    for thisqie in qie:
      if (thisqie<10 and thisqie>=0):
        ylist.append(thisrbx+'QIE0'+str(thisqie))
      else:
        ylist.append(thisrbx+'QIE'+str(thisqie))

      if subdet in ('ngHFP','ngHFM'):
        cursor = c.execute("SELECT ngRBX, QIE10, QIEFI, FI_CH, Crate, uHTR, uHTR_FI, Side, Eta, Phi, Depth from ngHFLogicalMap where ngRBX=? AND QIE10=? ORDER BY QIEFI,FI_CH", (thisrbx,thisqie))
      zlistrbxqie=[]
      for row in cursor:
        if(len(ylist)==1):
          xlist.append('QIEFI'+str(row[2])+'FICH'+str(row[3]))
        
        if var=='Crate':
          zlistrbxqie.append(row[4])
        elif var=='uHTR':
          zlistrbxqie.append(row[5])
        elif var=='uHTR_FI':
          zlistrbxqie.append(row[6])
        elif var=='Eta': 
          zlistrbxqie.append(row[7]*row[8])
        elif var=='Phi':
          zlistrbxqie.append(row[9])
        elif var=='Depth': 
          zlistrbxqie.append(row[10])
      zlist.append(zlistrbxqie)
  print "Operation done successfully";
  conn.close()

  fig = ff.create_annotated_heatmap(zlist, x=xlist, y=ylist, colorscale='Viridis')
  fig['layout']['xaxis'].update(side='bottom')
  fig['layout'].update(height=1500, width=1500, title=subdet+' '+var+' in FrontEnd coordiantes')
  plt.plot(fig, filename=subdet+'_'+var+'_in_FrontEnd')

def ValidationPlot_HO_FEC(subdet,var):
  conn = sqlite3.connect('../officialMap/HCALLogicalMap.db')
  c = conn.cursor()
  print "Opened database successfully";

  xlist = []
  ylist = []
  zlist = []
  ztext = []

  rbx_ho0 = ['HO001','HO002','HO003','HO004','HO005','HO006','HO007','HO008','HO009','HO010','HO011','HO012']
  rbx_ho1p = ['HO1P02','HO1P04','HO1P06','HO1P08','HO1P10','HO1P12']
  rbx_ho1m = ['HO1M02','HO1M04','HO1M06','HO1M08','HO1M10','HO1M12']
  rbx_ho2p = ['HO2P02','HO2P04','HO2P06','HO2P08','HO2P10','HO2P12']
  rbx_ho2m = ['HO2M02','HO2M04','HO2M06','HO2M08','HO2M10','HO2M12']

  if subdet in ('HO0'):
    rbx=rbx_ho0
  elif subdet in ('HO1P'):
    rbx=rbx_ho1p
  elif subdet in ('HO1M'):
    rbx=rbx_ho1m
  elif subdet in ('HO2P'):
    rbx=rbx_ho2p
  elif subdet in ('HO2M'):
    rbx=rbx_ho2m
  rm_ho0=[1,2,3]
  rm_hopm12=[1,2,3,4]  
  if subdet in ('HO0'):
    rm=rm_ho0
  else:
    rm=rm_hopm12

  for thisrbx in rbx:
    for thisrm in rm:
      if thisrbx in ('HO002','HO003','HO006','HO007','HO010','HO011'):
        ylist.append(thisrbx+'RM'+str(thisrm+1))
        cursor = c.execute("SELECT RBX, RM, RM_FI, FI_CH, Crate, HTR, HTR_FI, Side, Eta, Phi, Depth from HOLogicalMap where RBX=? AND RM=? ORDER BY RM_FI,FI_CH", (thisrbx,thisrm+1))
      else:
        ylist.append(thisrbx+'RM'+str(thisrm))
        cursor = c.execute("SELECT RBX, RM, RM_FI, FI_CH, Crate, HTR, HTR_TB, HTR_FI, Side, Eta, Phi, Depth from HOLogicalMap where RBX=? AND RM=? ORDER BY RM_FI,FI_CH", (thisrbx,thisrm))
      zlistrbxrm=[]
      ztextrbxrm=[]
      for row in cursor:
        if(len(ylist)==1):
          xlist.append('RMFI'+str(row[2])+'FICH'+str(row[3]))
        if var=='Crate':
          zlistrbxrm.append(row[4])
        elif var=='HTR':
          zlistrbxrm.append(row[5])
        elif var=='HTR_TB':
          if row[6]=='top':
            zlistrbxrm.append(1)
            ztextrbxrm.append('t')
          else:
            zlistrbxrm.append(0)
            ztextrbxrm.append('b')
        elif var=='HTR_FI':
          zlistrbxrm.append(row[7])
        elif var=='Eta': 
          zlistrbxrm.append(row[8]*row[9])
        elif var=='Phi':
          zlistrbxrm.append(row[10])
        elif var=='Depth': 
          zlistrbxrm.append(row[11])
      zlist.append(zlistrbxrm)
      if var=='HTR_TB':
        ztext.append(ztextrbxrm)
  print "Operation done successfully";
  conn.close()
  
  if var=='HTR_TB':
    fig = ff.create_annotated_heatmap(zlist, x=xlist, y=ylist, annotation_text=ztext, colorscale='Viridis')
  else:
    fig = ff.create_annotated_heatmap(zlist, x=xlist, y=ylist, colorscale='Viridis')
  fig['layout']['xaxis'].update(side='bottom')
  fig['layout'].update(height=1500, width=1500, title=subdet+' '+var+' in FrontEnd coordiantes')
  plt.plot(fig, filename=subdet+'_'+var+'_in_FrontEnd')

def main():
  #ValidationPlot_HBHE_FEC(sys.argv[1],sys.argv[2])
  #ValidationPlot_HF_FEC(sys.argv[1],sys.argv[2])
  ValidationPlot_HO_FEC(sys.argv[1],sys.argv[2])
  #for arg in sys.argv[1:]:
  #  print arg

if __name__ == "__main__":
  main()
