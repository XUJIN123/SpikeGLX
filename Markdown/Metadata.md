# Metafile Tags

* Typical right-hand-side values are shown for each tag illustrating whether
its data are integers, floating-point values or text strings.

* Inapplicable values are usually blank, like so: `userNotes=`

* Inapplicable tags may be absent.

## Common to All Files

```
appVersion=20161201
```

```
typeEnabled=imec,nidq
```

```
typeThis=nidq
```

```
gateMode=Immediate
```

Possible values are {Immediate, TCP}.

```
trigMode=Timed
```

Possible values are {Immediate, Timed, TTL, Spike, TCP}.

```
userNotes=Line1\nLine2...
```

Blank lines in your text are each replaced with '\n'. The `userNotes`
tag is thereby a single line in metafiles.

```
nSavedChans=257
```

The number of channels being saved to disk.

```
snsSaveChanSubset=2,4,8,12:150
snsSaveChanSubset=all
```

Two examples are shown above for `snsSaveChanSubset`. If any channels
are NOT being saved the value is a printer-like list of channels that ARE
saved. If ALL are saved, the value is 'all'.

```
rmt_USERTYPE=USERDEFINED
```

When SpikeGLX is set as a Gate/Trigger server it can receive remote
commands to start and stop gate and trigger intervals. It can also receive
remote commands to insert custom metadata into saved files. Such tags are
automatically prepended with 'rmt_' to distinguish them from built-in tags.


```
fileName=C:/SGL_DATA/qqq1_g0_t0.nidq.bin
```

This is the original path to the binary file paired with this metadata file.

```
fileCreateTime=2017-02-06T13:34:39
```

These are the local date and time on the recording machine.

```
fileTimeSecs=1.0
```

This is the span of the file data in seconds.

```
fileSizeBytes=10144818
```

```
firstSample=779283
```

All acquired samples are assigned an index number; the first acquired
during the run is sample 0. This value is the index number of the first
sample recorded in this file.

```
fileSHA1=B209BBB956A9F6371625C118D651DBE9AED4051D
```

This is a checksum calculated for the binary data. Use menu item
`Tools::Verify SHA1` to detect if the binary data have been altered since
the file was first recorded.

```
~snsShankMap=(1,2,96)(0:0:0:1)(0:1:0:1)(0:0:1:1)(0:1:1:1)(0:0:2:1)(0:1:2:1)(0:0:3:1)(0:1:3:1)(0:0:4:1)(0:1:4:1)(0:0:5:1)(0:1:5:1)(0:0:6:1)(0:1:6:1)(0:0:7:1)(0:1:7:1)(0:0:8:1)(0:1:8:1)(0:0:9:1)(0:1:9:1)(0:0:10:1)(0:1:10:1)(0:0:11:1)(0:1:11:1)(0:0:12:1)(0:1:12:1)(0:0:13:1)(0:1:13:1)(0:0:14:1)(0:1:14:1)(0:0:15:1)(0:1:15:1)(0:0:16:1)(0:1:16:1)(0:0:17:1)(0:1:17:1)(0:0:18:1)(0:1:18:1)(0:0:19:1)(0:1:19:1)(0:0:20:1)(0:1:20:1)(0:0:21:1)(0:1:21:1)(0:0:22:1)(0:1:22:1)(0:0:23:1)(0:1:23:1)(0:0:24:1)(0:1:24:1)(0:0:25:1)(0:1:25:1)(0:0:26:1)(0:1:26:1)(0:0:27:1)(0:1:27:1)(0:0:28:1)(0:1:28:1)(0:0:29:1)(0:1:29:1)(0:0:30:1)(0:1:30:1)(0:0:31:1)(0:1:31:1)(0:0:32:1)(0:1:32:1)(0:0:33:1)(0:1:33:1)(0:0:34:1)(0:1:34:1)(0:0:35:1)(0:1:35:1)(0:0:36:1)(0:1:36:1)(0:0:37:1)(0:1:37:1)(0:0:38:1)(0:1:38:1)(0:0:39:1)(0:1:39:1)(0:0:40:1)(0:1:40:1)(0:0:41:1)(0:1:41:1)(0:0:42:1)(0:1:42:1)(0:0:43:1)(0:1:43:1)(0:0:44:1)(0:1:44:1)(0:0:45:1)(0:1:45:1)(0:0:46:1)(0:1:46:1)(0:0:47:1)(0:1:47:1)(0:0:48:1)(0:1:48:1)(0:0:49:1)(0:1:49:1)(0:0:50:1)(0:1:50:1)(0:0:51:1)(0:1:51:1)(0:0:52:1)(0:1:52:1)(0:0:53:1)(0:1:53:1)(0:0:54:1)(0:1:54:1)(0:0:55:1)(0:1:55:1)(0:0:56:1)(0:1:56:1)(0:0:57:1)(0:1:57:1)(0:0:58:1)(0:1:58:1)(0:0:59:1)(0:1:59:1)(0:0:60:1)(0:1:60:1)(0:0:61:1)(0:1:61:1)(0:0:62:1)(0:1:62:1)(0:0:63:1)(0:1:63:1)(0:0:64:1)(0:1:64:1)(0:0:65:1)(0:1:65:1)(0:0:66:1)(0:1:66:1)(0:0:67:1)(0:1:67:1)(0:0:68:1)(0:1:68:1)(0:0:69:1)(0:1:69:1)(0:0:70:1)(0:1:70:1)(0:0:71:1)(0:1:71:1)(0:0:72:1)(0:1:72:1)(0:0:73:1)(0:1:73:1)(0:0:74:1)(0:1:74:1)(0:0:75:1)(0:1:75:1)(0:0:76:1)(0:1:76:1)(0:0:77:1)(0:1:77:1)(0:0:78:1)(0:1:78:1)(0:0:79:1)(0:1:79:1)(0:0:80:1)(0:1:80:1)(0:0:81:1)(0:1:81:1)(0:0:82:1)(0:1:82:1)(0:0:83:1)(0:1:83:1)(0:0:84:1)(0:1:84:1)(0:0:85:1)(0:1:85:1)(0:0:86:1)(0:1:86:1)(0:0:87:1)(0:1:87:1)(0:0:88:1)(0:1:88:1)(0:0:89:1)(0:1:89:1)(0:0:90:1)(0:1:90:1)(0:0:91:1)(0:1:91:1)(0:0:92:1)(0:1:92:1)(0:0:93:1)(0:1:93:1)(0:0:94:1)(0:1:94:1)(0:0:95:1)(0:1:95:1)
```

The Shank Map describes how electrodes are arranged on the probe. The first
() entry is a header, here, (1,2,96) indicates the probe has up to 1 shank
with up to 2 columns and 96 rows. Note that these are maximum values that
define a grid, but not all column and row combinations need be occupied.
Each following electrode entry has four values:

1. zero-based shank #,

2. zero-based col #,

3. zero-based row #,

4. 0/1 flag indicating if the electrode should be drawn in the
ShankView window, and if it should be considered in spatial average \<S\>
calculations.

>Note: There are electrode entries only for saved channels.

## If Using Timed Trigger

```
trgTimTL0=10.0
```

This is the number of seconds to wait from the start of a gate window,
until starting the first high-phase (write-phase).

```
trgTimTH=1.0
```

This is the number of seconds of data to write, unless overridden by
`trgTimIsHInf`.

```
trgTimTL=1.0
```

This is the number of seconds to wait between write-phases.

```
trgTimNH=1
```

This is the number of high-low cycles per gate window, unless overridden by
`trgTimIsNInf`.

```
trgTimIsHInf=false
```

Is the duration of the high cycle infinite (latched high)? If not `trgTimTH`
sets the duration.

```
trgTimIsNInf=false
```

Is the count of high cycles infinite? If not, `trgTimNH` sets the count.

>Note that infinite cycle counts or durations are terminated when either
the current gate goes low or the run is stopped manually.

## If Using TTL Trigger

```
trgTTLMarginS=1.0
```

This is the number of seconds to add both before and after the peri-event
interval to provide expanded context.

```
trgTTLRefractS=0.5
```

This is the minimum number of seconds to wait since the last rising-edge
until the rising-edge detector may be re-armed.

```
trgTTLTH=0.5
```

This is the programmed high duration if `trgTTLMode=1`.

```
trgTTLStream=nidq
```

```
trgTTLMode=0
```

Once a rising edge is detected, the mode controls how the length of the
high-phase (file-writing phase) is determined.

Possible values: {0=Latch high, 1=Timed high, 2=Follow TTL}.

```
trgTTLAIChan=192
```

```
trgTTLBit=0
```

```
trgTTLInarow=5
```

This is the count in consecutive samples that must also be high to confirm
that a rising edge is real rather than noise. This is sometimes referred to
as an "anti-bounce" feature.

```
trgTTLNH=10
```

This is the count of writing cycles to execute per gate window, unless
overridden by `trgTTLIsNInf`.

```
trgTTLThresh=2.0
```

This is the voltage threshold used for testing analog-type channels.

```
trgTTLIsAnalog=true
```

If true, `trgTTLAIChan` specifies which analog channel in the stream will
be tested for rising edges. If false, `trgTTLBit` specifies which bit of
the 16-bit digital data words will be tested. The digital data words are
the last words in each timepoint. The bits within are arranged like this:

[analog0][analog1]...[analogN][bit15..bit0][bit31..bit16]...[digitalN].

```
trgTTLIsNInf=true
```

Is the count of high cycles infinite? If not, `trgTTLNH` sets the count.

>Note that infinite cycle counts or durations are terminated when either
the current gate goes low or the run is stopped manually.

## If Using Spike Trigger

```
trgSpikePeriEvtS=1.0
```

This is the number of seconds to add both before and after the peri-event
interval to provide expanded context.

```
trgSpikeRefractS=0.5
```

This is the minimum number of seconds to wait since the last spike until the
falling-edge detector may be re-armed.

```
trgSpikeStream=nidq
```

```
trgSpikeAIChan=4
```

```
trgSpikeInarow=5
```

This is the count in consecutive samples that must also be low to confirm
that a falling edge is a real spike rather than noise.

```
trgSpikeNS=10
```

Maximum number of spikes to detect (files to write) per gate window.

```
trgSpikeThresh=-100e-6
```

This trigger defines a spike as a negative-going threshold crossing.

```
trgSpikeIsNInf=false
```

>Note that infinite cycle counts or durations are terminated when either
the current gate goes low or the run is stopped manually.

## NIDQ

```
niAiRangeMin=2.5
```

```
niAiRangeMax=-2.5
```

Convert from 16-bit analog values (i) to voltages (V) as follows:

V = i * Vmax / Imax / gain.

For nidq data:

* Imax = 32768
* Vmax = `niAiRangeMax`
* gain = `niMNGain` or `niMAGain`, accordingly.

```
niSampRate=19737
```

```
niMNGain=200.0
```

```
niMAGain=1.0
```

```
niDev1=Dev1
```

```
niDev1ProductName=FakeDAQ
```

```
niClock1=PFI2
```

```
niMNChans1=0:5
```

```
niMAChans1=6:7
```

```
niXAChans1=
```

```
niXDChans1=1
```

This is a printer-like list of NI-DAQ line indices. For example, if your
NI device was named 'Fred' and if niXDChans1=2:3, we would acquire from
lines {Fred/line2, Fred/line3}.

```
niMuxFactor=32
```

```
niAiTermination=Default
```

```
niSyncEnable=true
```

```
niSyncLine=Dev1/port0/line0
```

```
acqMnMaXaDw=192,64,0,1
```

This is the count of channels, of each type, in each timepoint,
at acquisition time.

```
snsMnMaXaDw=192,64,0,1
```

This is the count of channels, of each type, in each timepoint,
as stored in the binary file.

```
~snsChanMap=(6,2,32,0,1)(MN0C0;0:0)(MN0C1;1:1)(MN0C2;2:2)(MN0C3;3:3)(MN0C4;4:4)(MN0C5;5:5)(MN0C6;6:6)(MN0C7;7:7)(MN0C8;8:8)(MN0C9;9:9)(MN0C10;10:10)(MN0C11;11:11)(MN0C12;12:12)(MN0C13;13:13)(MN0C14;14:14)(MN0C15;15:15)(MN0C16;16:16)(MN0C17;17:17)(MN0C18;18:18)(MN0C19;19:19)(MN0C20;20:20)(MN0C21;21:21)(MN0C22;22:22)(MN0C23;23:23)(MN0C24;24:24)(MN0C25;25:25)(MN0C26;26:26)(MN0C27;27:27)(MN0C28;28:28)(MN0C29;29:29)(MN0C30;30:30)(MN0C31;31:31)(MN1C0;32:32)(MN1C1;33:33)(MN1C2;34:34)(MN1C3;35:35)(MN1C4;36:36)(MN1C5;37:37)(MN1C6;38:38)(MN1C7;39:39)(MN1C8;40:40)(MN1C9;41:41)(MN1C10;42:42)(MN1C11;43:43)(MN1C12;44:44)(MN1C13;45:45)(MN1C14;46:46)(MN1C15;47:47)(MN1C16;48:48)(MN1C17;49:49)(MN1C18;50:50)(MN1C19;51:51)(MN1C20;52:52)(MN1C21;53:53)(MN1C22;54:54)(MN1C23;55:55)(MN1C24;56:56)(MN1C25;57:57)(MN1C26;58:58)(MN1C27;59:59)(MN1C28;60:60)(MN1C29;61:61)(MN1C30;62:62)(MN1C31;63:63)(MN2C0;64:64)(MN2C1;65:65)(MN2C2;66:66)(MN2C3;67:67)(MN2C4;68:68)(MN2C5;69:69)(MN2C6;70:70)(MN2C7;71:71)(MN2C8;72:72)(MN2C9;73:73)(MN2C10;74:74)(MN2C11;75:75)(MN2C12;76:76)(MN2C13;77:77)(MN2C14;78:78)(MN2C15;79:79)(MN2C16;80:80)(MN2C17;81:81)(MN2C18;82:82)(MN2C19;83:83)(MN2C20;84:84)(MN2C21;85:85)(MN2C22;86:86)(MN2C23;87:87)(MN2C24;88:88)(MN2C25;89:89)(MN2C26;90:90)(MN2C27;91:91)(MN2C28;92:92)(MN2C29;93:93)(MN2C30;94:94)(MN2C31;95:95)(MN3C0;96:96)(MN3C1;97:97)(MN3C2;98:98)(MN3C3;99:99)(MN3C4;100:100)(MN3C5;101:101)(MN3C6;102:102)(MN3C7;103:103)(MN3C8;104:104)(MN3C9;105:105)(MN3C10;106:106)(MN3C11;107:107)(MN3C12;108:108)(MN3C13;109:109)(MN3C14;110:110)(MN3C15;111:111)(MN3C16;112:112)(MN3C17;113:113)(MN3C18;114:114)(MN3C19;115:115)(MN3C20;116:116)(MN3C21;117:117)(MN3C22;118:118)(MN3C23;119:119)(MN3C24;120:120)(MN3C25;121:121)(MN3C26;122:122)(MN3C27;123:123)(MN3C28;124:124)(MN3C29;125:125)(MN3C30;126:126)(MN3C31;127:127)(MN4C0;128:128)(MN4C1;129:129)(MN4C2;130:130)(MN4C3;131:131)(MN4C4;132:132)(MN4C5;133:133)(MN4C6;134:134)(MN4C7;135:135)(MN4C8;136:136)(MN4C9;137:137)(MN4C10;138:138)(MN4C11;139:139)(MN4C12;140:140)(MN4C13;141:141)(MN4C14;142:142)(MN4C15;143:143)(MN4C16;144:144)(MN4C17;145:145)(MN4C18;146:146)(MN4C19;147:147)(MN4C20;148:148)(MN4C21;149:149)(MN4C22;150:150)(MN4C23;151:151)(MN4C24;152:152)(MN4C25;153:153)(MN4C26;154:154)(MN4C27;155:155)(MN4C28;156:156)(MN4C29;157:157)(MN4C30;158:158)(MN4C31;159:159)(MN5C0;160:160)(MN5C1;161:161)(MN5C2;162:162)(MN5C3;163:163)(MN5C4;164:164)(MN5C5;165:165)(MN5C6;166:166)(MN5C7;167:167)(MN5C8;168:168)(MN5C9;169:169)(MN5C10;170:170)(MN5C11;171:171)(MN5C12;172:172)(MN5C13;173:173)(MN5C14;174:174)(MN5C15;175:175)(MN5C16;176:176)(MN5C17;177:177)(MN5C18;178:178)(MN5C19;179:179)(MN5C20;180:180)(MN5C21;181:181)(MN5C22;182:182)(MN5C23;183:183)(MN5C24;184:184)(MN5C25;185:185)(MN5C26;186:186)(MN5C27;187:187)(MN5C28;188:188)(MN5C29;189:189)(MN5C30;190:190)(MN5C31;191:191)(MA0C0;192:192)(MA0C1;193:193)(MA0C2;194:194)(MA0C3;195:195)(MA0C4;196:196)(MA0C5;197:197)(MA0C6;198:198)(MA0C7;199:199)(MA0C8;200:200)(MA0C9;201:201)(MA0C10;202:202)(MA0C11;203:203)(MA0C12;204:204)(MA0C13;205:205)(MA0C14;206:206)(MA0C15;207:207)(MA0C16;208:208)(MA0C17;209:209)(MA0C18;210:210)(MA0C19;211:211)(MA0C20;212:212)(MA0C21;213:213)(MA0C22;214:214)(MA0C23;215:215)(MA0C24;216:216)(MA0C25;217:217)(MA0C26;218:218)(MA0C27;219:219)(MA0C28;220:220)(MA0C29;221:221)(MA0C30;222:222)(MA0C31;223:223)(MA1C0;224:224)(MA1C1;225:225)(MA1C2;226:226)(MA1C3;227:227)(MA1C4;228:228)(MA1C5;229:229)(MA1C6;230:230)(MA1C7;231:231)(MA1C8;232:232)(MA1C9;233:233)(MA1C10;234:234)(MA1C11;235:235)(MA1C12;236:236)(MA1C13;237:237)(MA1C14;238:238)(MA1C15;239:239)(MA1C16;240:240)(MA1C17;241:241)(MA1C18;242:242)(MA1C19;243:243)(MA1C20;244:244)(MA1C21;245:245)(MA1C22;246:246)(MA1C23;247:247)(MA1C24;248:248)(MA1C25;249:249)(MA1C26;250:250)(MA1C27;251:251)(MA1C28;252:252)(MA1C29;253:253)(MA1C30;254:254)(MA1C31;255:255)(XD0;256:256)
```

The channel map describes the order of graphs in SpikeGLX displays. The
header for the nidq stream, here (6,2,32,0,1) indicates there are:

* 6 MN-type NI-DAQ input channels,
* 2 MA-type NI-DAQ input channels,
* 32 multiplexed logical channels per MN/MA input,
* 0 XA NI-DAQ channels,
* 1 XD NI-DAQ line.

Each subsequent entry in the map has two fields, (:)-separated:

* Channel name, e.g., 'MN0C2;2'
* Zero-based order index.

>Note: There are map entries only for saved channels.

### If Using 2nd NIDQ Card

```
niDualDevMode=true
```

```
niDev2
```

```
niDev2ProductName
```

```
niClock2
```

```
niMNChans2
```

```
niMAChans2
```

```
niXAChans2
```

```
niXDChans2
```

## IMEC

```
imAiRangeMin=-0.6
```

```
imAiRangeMax=0.6
```

Convert from 16-bit analog values (i) to voltages (V) as follows:

V = i * Vmax / Imax / gain.

For imec data:

* Imax = 512
* Vmax = `imAiRangeMax`
* gain = imroTbl gain entry for AP or LF type.

```
imSampRate=30000
```

```
imRoFile=
```

This is a path to your custom Imec Readout Table (imRo) file. If you
elect default settings no file is needed. The active table content is
stored as tag `~imroTbl` whether custom or default.

```
imStdby=0:12,45
```

These channels of an option 3 probe had been placed in stand-by mode,
which means their analog amplifiers were switched off. Stand-by channels
are still read from the hardware and stored in the data stream. The only
reason to set stand-by mode is to reduce noise/crosstalk in the system.

```
imHpFlt=300
```

```
imDoGainCor=true
```

```
imNoLEDs=false
```

```
imSoftStart=true
```

If true, Imec data acquisition begins on receiving a software command from
SpikeGLX. If false, the hardware is set to await a hardware trigger on the
'Ext. Start' pin of the BSC. Hardware start is not yet implemented.

```
imVersHwr=0.0
```

This is the Xilinx bootcode version number. The '.' separates the major
and minor revision numbers.

```
imVersBs=0.0
```

This is the BSC version number. The '.' separates the major
and minor revision numbers.

```
imVersAPI=0.0
```

This is the Imec API version number. The '.' separates the major
and minor revision numbers.

```
imProbeSN=513180531
```

```
imProbeOpt=3
```

```
acqApLfSy=384,384,1
```

This is the count of channels, of each type, in each timepoint,
at acquisition time.

```
snsApLfSy=384,0,1
```

This is the count of channels, of each type, in each timepoint,
as stored in the binary file.

```
~imroTbl=(0,3,384)(0 0 0 500 250)(1 0 0 500 250)(2 0 0 500 250)(3 0 0 500 250)(4 0 0 500 250)(5 0 0 500 250)(6 0 0 500 250)(7 0 0 500 250)(8 0 0 500 250)(9 0 0 500 250)(10 0 0 500 250)(11 0 0 500 250)(12 0 0 500 250)(13 0 0 500 250)(14 0 0 500 250)(15 0 0 500 250)(16 0 0 500 250)(17 0 0 500 250)(18 0 0 500 250)(19 0 0 500 250)(20 0 0 500 250)(21 0 0 500 250)(22 0 0 500 250)(23 0 0 500 250)(24 0 0 500 250)(25 0 0 500 250)(26 0 0 500 250)(27 0 0 500 250)(28 0 0 500 250)(29 0 0 500 250)(30 0 0 500 250)(31 0 0 500 250)(32 0 0 500 250)(33 0 0 500 250)(34 0 0 500 250)(35 0 0 500 250)(36 0 0 500 250)(37 0 0 500 250)(38 0 0 500 250)(39 0 0 500 250)(40 0 0 500 250)(41 0 0 500 250)(42 0 0 500 250)(43 0 0 500 250)(44 0 0 500 250)(45 0 0 500 250)(46 0 0 500 250)(47 0 0 500 250)(48 0 0 500 250)(49 0 0 500 250)(50 0 0 500 250)(51 0 0 500 250)(52 0 0 500 250)(53 0 0 500 250)(54 0 0 500 250)(55 0 0 500 250)(56 0 0 500 250)(57 0 0 500 250)(58 0 0 500 250)(59 0 0 500 250)(60 0 0 500 250)(61 0 0 500 250)(62 0 0 500 250)(63 0 0 500 250)(64 0 0 500 250)(65 0 0 500 250)(66 0 0 500 250)(67 0 0 500 250)(68 0 0 500 250)(69 0 0 500 250)(70 0 0 500 250)(71 0 0 500 250)(72 0 0 500 250)(73 0 0 500 250)(74 0 0 500 250)(75 0 0 500 250)(76 0 0 500 250)(77 0 0 500 250)(78 0 0 500 250)(79 0 0 500 250)(80 0 0 500 250)(81 0 0 500 250)(82 0 0 500 250)(83 0 0 500 250)(84 0 0 500 250)(85 0 0 500 250)(86 0 0 500 250)(87 0 0 500 250)(88 0 0 500 250)(89 0 0 500 250)(90 0 0 500 250)(91 0 0 500 250)(92 0 0 500 250)(93 0 0 500 250)(94 0 0 500 250)(95 0 0 500 250)(96 0 0 500 250)(97 0 0 500 250)(98 0 0 500 250)(99 0 0 500 250)(100 0 0 500 250)(101 0 0 500 250)(102 0 0 500 250)(103 0 0 500 250)(104 0 0 500 250)(105 0 0 500 250)(106 0 0 500 250)(107 0 0 500 250)(108 0 0 500 250)(109 0 0 500 250)(110 0 0 500 250)(111 0 0 500 250)(112 0 0 500 250)(113 0 0 500 250)(114 0 0 500 250)(115 0 0 500 250)(116 0 0 500 250)(117 0 0 500 250)(118 0 0 500 250)(119 0 0 500 250)(120 0 0 500 250)(121 0 0 500 250)(122 0 0 500 250)(123 0 0 500 250)(124 0 0 500 250)(125 0 0 500 250)(126 0 0 500 250)(127 0 0 500 250)(128 0 0 500 250)(129 0 0 500 250)(130 0 0 500 250)(131 0 0 500 250)(132 0 0 500 250)(133 0 0 500 250)(134 0 0 500 250)(135 0 0 500 250)(136 0 0 500 250)(137 0 0 500 250)(138 0 0 500 250)(139 0 0 500 250)(140 0 0 500 250)(141 0 0 500 250)(142 0 0 500 250)(143 0 0 500 250)(144 0 0 500 250)(145 0 0 500 250)(146 0 0 500 250)(147 0 0 500 250)(148 0 0 500 250)(149 0 0 500 250)(150 0 0 500 250)(151 0 0 500 250)(152 0 0 500 250)(153 0 0 500 250)(154 0 0 500 250)(155 0 0 500 250)(156 0 0 500 250)(157 0 0 500 250)(158 0 0 500 250)(159 0 0 500 250)(160 0 0 500 250)(161 0 0 500 250)(162 0 0 500 250)(163 0 0 500 250)(164 0 0 500 250)(165 0 0 500 250)(166 0 0 500 250)(167 0 0 500 250)(168 0 0 500 250)(169 0 0 500 250)(170 0 0 500 250)(171 0 0 500 250)(172 0 0 500 250)(173 0 0 500 250)(174 0 0 500 250)(175 0 0 500 250)(176 0 0 500 250)(177 0 0 500 250)(178 0 0 500 250)(179 0 0 500 250)(180 0 0 500 250)(181 0 0 500 250)(182 0 0 500 250)(183 0 0 500 250)(184 0 0 500 250)(185 0 0 500 250)(186 0 0 500 250)(187 0 0 500 250)(188 0 0 500 250)(189 0 0 500 250)(190 0 0 500 250)(191 0 0 500 250)(192 0 0 500 250)(193 0 0 500 250)(194 0 0 500 250)(195 0 0 500 250)(196 0 0 500 250)(197 0 0 500 250)(198 0 0 500 250)(199 0 0 500 250)(200 0 0 500 250)(201 0 0 500 250)(202 0 0 500 250)(203 0 0 500 250)(204 0 0 500 250)(205 0 0 500 250)(206 0 0 500 250)(207 0 0 500 250)(208 0 0 500 250)(209 0 0 500 250)(210 0 0 500 250)(211 0 0 500 250)(212 0 0 500 250)(213 0 0 500 250)(214 0 0 500 250)(215 0 0 500 250)(216 0 0 500 250)(217 0 0 500 250)(218 0 0 500 250)(219 0 0 500 250)(220 0 0 500 250)(221 0 0 500 250)(222 0 0 500 250)(223 0 0 500 250)(224 0 0 500 250)(225 0 0 500 250)(226 0 0 500 250)(227 0 0 500 250)(228 0 0 500 250)(229 0 0 500 250)(230 0 0 500 250)(231 0 0 500 250)(232 0 0 500 250)(233 0 0 500 250)(234 0 0 500 250)(235 0 0 500 250)(236 0 0 500 250)(237 0 0 500 250)(238 0 0 500 250)(239 0 0 500 250)(240 0 0 500 250)(241 0 0 500 250)(242 0 0 500 250)(243 0 0 500 250)(244 0 0 500 250)(245 0 0 500 250)(246 0 0 500 250)(247 0 0 500 250)(248 0 0 500 250)(249 0 0 500 250)(250 0 0 500 250)(251 0 0 500 250)(252 0 0 500 250)(253 0 0 500 250)(254 0 0 500 250)(255 0 0 500 250)(256 0 0 500 250)(257 0 0 500 250)(258 0 0 500 250)(259 0 0 500 250)(260 0 0 500 250)(261 0 0 500 250)(262 0 0 500 250)(263 0 0 500 250)(264 0 0 500 250)(265 0 0 500 250)(266 0 0 500 250)(267 0 0 500 250)(268 0 0 500 250)(269 0 0 500 250)(270 0 0 500 250)(271 0 0 500 250)(272 0 0 500 250)(273 0 0 500 250)(274 0 0 500 250)(275 0 0 500 250)(276 0 0 500 250)(277 0 0 500 250)(278 0 0 500 250)(279 0 0 500 250)(280 0 0 500 250)(281 0 0 500 250)(282 0 0 500 250)(283 0 0 500 250)(284 0 0 500 250)(285 0 0 500 250)(286 0 0 500 250)(287 0 0 500 250)(288 0 0 500 250)(289 0 0 500 250)(290 0 0 500 250)(291 0 0 500 250)(292 0 0 500 250)(293 0 0 500 250)(294 0 0 500 250)(295 0 0 500 250)(296 0 0 500 250)(297 0 0 500 250)(298 0 0 500 250)(299 0 0 500 250)(300 0 0 500 250)(301 0 0 500 250)(302 0 0 500 250)(303 0 0 500 250)(304 0 0 500 250)(305 0 0 500 250)(306 0 0 500 250)(307 0 0 500 250)(308 0 0 500 250)(309 0 0 500 250)(310 0 0 500 250)(311 0 0 500 250)(312 0 0 500 250)(313 0 0 500 250)(314 0 0 500 250)(315 0 0 500 250)(316 0 0 500 250)(317 0 0 500 250)(318 0 0 500 250)(319 0 0 500 250)(320 0 0 500 250)(321 0 0 500 250)(322 0 0 500 250)(323 0 0 500 250)(324 0 0 500 250)(325 0 0 500 250)(326 0 0 500 250)(327 0 0 500 250)(328 0 0 500 250)(329 0 0 500 250)(330 0 0 500 250)(331 0 0 500 250)(332 0 0 500 250)(333 0 0 500 250)(334 0 0 500 250)(335 0 0 500 250)(336 0 0 500 250)(337 0 0 500 250)(338 0 0 500 250)(339 0 0 500 250)(340 0 0 500 250)(341 0 0 500 250)(342 0 0 500 250)(343 0 0 500 250)(344 0 0 500 250)(345 0 0 500 250)(346 0 0 500 250)(347 0 0 500 250)(348 0 0 500 250)(349 0 0 500 250)(350 0 0 500 250)(351 0 0 500 250)(352 0 0 500 250)(353 0 0 500 250)(354 0 0 500 250)(355 0 0 500 250)(356 0 0 500 250)(357 0 0 500 250)(358 0 0 500 250)(359 0 0 500 250)(360 0 0 500 250)(361 0 0 500 250)(362 0 0 500 250)(363 0 0 500 250)(364 0 0 500 250)(365 0 0 500 250)(366 0 0 500 250)(367 0 0 500 250)(368 0 0 500 250)(369 0 0 500 250)(370 0 0 500 250)(371 0 0 500 250)(372 0 0 500 250)(373 0 0 500 250)(374 0 0 500 250)(375 0 0 500 250)(376 0 0 500 250)(377 0 0 500 250)(378 0 0 500 250)(379 0 0 500 250)(380 0 0 500 250)(381 0 0 500 250)(382 0 0 500 250)(383 0 0 500 250)
```

The first entry of the Imec Readout Table (imRo) is a header. Here, (0,3,384)
indicates probe serial number, probe option, number of channels. Each
subsequent channel entry has five values:

* Channel number,
* Bank number of the connected electrode,
* Reference ID index,
* AP band gain,
* LF band gain.

The reference ID is zero if an external reference is used. For an option
1,2,3 probe the ID is a one-based index selecting one of 10 channels:

{36, 75, 112, 151, 188, 227, 264, 303, 340, 379}.

For an option 4 probe the ID is a one-based index selecting one of 7 channels:

{36, 75, 112, 151, 188, 227, 264}.

>Note: Unlike snsShankMap and snsChanMap which store entries only for saved
channels, the imroTbl always has entries for all acquired channels.

```
~snsChanMap=(384,384,1)(AP0;0:0)(AP1;1:1)(AP2;2:2)(AP3;3:3)(AP4;4:4)(AP5;5:5)(AP6;6:6)(AP7;7:7)(AP8;8:8)(AP9;9:9)(AP10;10:10)(AP11;11:11)(AP12;12:12)(AP13;13:13)(AP14;14:14)(AP15;15:15)(AP16;16:16)(AP17;17:17)(AP18;18:18)(AP19;19:19)(AP20;20:20)(AP21;21:21)(AP22;22:22)(AP23;23:23)(AP24;24:24)(AP25;25:25)(AP26;26:26)(AP27;27:27)(AP28;28:28)(AP29;29:29)(AP30;30:30)(AP31;31:31)(AP32;32:32)(AP33;33:33)(AP34;34:34)(AP35;35:35)(AP36;36:36)(AP37;37:37)(AP38;38:38)(AP39;39:39)(AP40;40:40)(AP41;41:41)(AP42;42:42)(AP43;43:43)(AP44;44:44)(AP45;45:45)(AP46;46:46)(AP47;47:47)(AP48;48:48)(AP49;49:49)(AP50;50:50)(AP51;51:51)(AP52;52:52)(AP53;53:53)(AP54;54:54)(AP55;55:55)(AP56;56:56)(AP57;57:57)(AP58;58:58)(AP59;59:59)(AP60;60:60)(AP61;61:61)(AP62;62:62)(AP63;63:63)(AP64;64:64)(AP65;65:65)(AP66;66:66)(AP67;67:67)(AP68;68:68)(AP69;69:69)(AP70;70:70)(AP71;71:71)(AP72;72:72)(AP73;73:73)(AP74;74:74)(AP75;75:75)(AP76;76:76)(AP77;77:77)(AP78;78:78)(AP79;79:79)(AP80;80:80)(AP81;81:81)(AP82;82:82)(AP83;83:83)(AP84;84:84)(AP85;85:85)(AP86;86:86)(AP87;87:87)(AP88;88:88)(AP89;89:89)(AP90;90:90)(AP91;91:91)(AP92;92:92)(AP93;93:93)(AP94;94:94)(AP95;95:95)(AP96;96:96)(AP97;97:97)(AP98;98:98)(AP99;99:99)(AP100;100:100)(AP101;101:101)(AP102;102:102)(AP103;103:103)(AP104;104:104)(AP105;105:105)(AP106;106:106)(AP107;107:107)(AP108;108:108)(AP109;109:109)(AP110;110:110)(AP111;111:111)(AP112;112:112)(AP113;113:113)(AP114;114:114)(AP115;115:115)(AP116;116:116)(AP117;117:117)(AP118;118:118)(AP119;119:119)(AP120;120:120)(AP121;121:121)(AP122;122:122)(AP123;123:123)(AP124;124:124)(AP125;125:125)(AP126;126:126)(AP127;127:127)(AP128;128:128)(AP129;129:129)(AP130;130:130)(AP131;131:131)(AP132;132:132)(AP133;133:133)(AP134;134:134)(AP135;135:135)(AP136;136:136)(AP137;137:137)(AP138;138:138)(AP139;139:139)(AP140;140:140)(AP141;141:141)(AP142;142:142)(AP143;143:143)(AP144;144:144)(AP145;145:145)(AP146;146:146)(AP147;147:147)(AP148;148:148)(AP149;149:149)(AP150;150:150)(AP151;151:151)(AP152;152:152)(AP153;153:153)(AP154;154:154)(AP155;155:155)(AP156;156:156)(AP157;157:157)(AP158;158:158)(AP159;159:159)(AP160;160:160)(AP161;161:161)(AP162;162:162)(AP163;163:163)(AP164;164:164)(AP165;165:165)(AP166;166:166)(AP167;167:167)(AP168;168:168)(AP169;169:169)(AP170;170:170)(AP171;171:171)(AP172;172:172)(AP173;173:173)(AP174;174:174)(AP175;175:175)(AP176;176:176)(AP177;177:177)(AP178;178:178)(AP179;179:179)(AP180;180:180)(AP181;181:181)(AP182;182:182)(AP183;183:183)(AP184;184:184)(AP185;185:185)(AP186;186:186)(AP187;187:187)(AP188;188:188)(AP189;189:189)(AP190;190:190)(AP191;191:191)(AP192;192:192)(AP193;193:193)(AP194;194:194)(AP195;195:195)(AP196;196:196)(AP197;197:197)(AP198;198:198)(AP199;199:199)(AP200;200:200)(AP201;201:201)(AP202;202:202)(AP203;203:203)(AP204;204:204)(AP205;205:205)(AP206;206:206)(AP207;207:207)(AP208;208:208)(AP209;209:209)(AP210;210:210)(AP211;211:211)(AP212;212:212)(AP213;213:213)(AP214;214:214)(AP215;215:215)(AP216;216:216)(AP217;217:217)(AP218;218:218)(AP219;219:219)(AP220;220:220)(AP221;221:221)(AP222;222:222)(AP223;223:223)(AP224;224:224)(AP225;225:225)(AP226;226:226)(AP227;227:227)(AP228;228:228)(AP229;229:229)(AP230;230:230)(AP231;231:231)(AP232;232:232)(AP233;233:233)(AP234;234:234)(AP235;235:235)(AP236;236:236)(AP237;237:237)(AP238;238:238)(AP239;239:239)(AP240;240:240)(AP241;241:241)(AP242;242:242)(AP243;243:243)(AP244;244:244)(AP245;245:245)(AP246;246:246)(AP247;247:247)(AP248;248:248)(AP249;249:249)(AP250;250:250)(AP251;251:251)(AP252;252:252)(AP253;253:253)(AP254;254:254)(AP255;255:255)(AP256;256:256)(AP257;257:257)(AP258;258:258)(AP259;259:259)(AP260;260:260)(AP261;261:261)(AP262;262:262)(AP263;263:263)(AP264;264:264)(AP265;265:265)(AP266;266:266)(AP267;267:267)(AP268;268:268)(AP269;269:269)(AP270;270:270)(AP271;271:271)(AP272;272:272)(AP273;273:273)(AP274;274:274)(AP275;275:275)(AP276;276:276)(AP277;277:277)(AP278;278:278)(AP279;279:279)(AP280;280:280)(AP281;281:281)(AP282;282:282)(AP283;283:283)(AP284;284:284)(AP285;285:285)(AP286;286:286)(AP287;287:287)(AP288;288:288)(AP289;289:289)(AP290;290:290)(AP291;291:291)(AP292;292:292)(AP293;293:293)(AP294;294:294)(AP295;295:295)(AP296;296:296)(AP297;297:297)(AP298;298:298)(AP299;299:299)(AP300;300:300)(AP301;301:301)(AP302;302:302)(AP303;303:303)(AP304;304:304)(AP305;305:305)(AP306;306:306)(AP307;307:307)(AP308;308:308)(AP309;309:309)(AP310;310:310)(AP311;311:311)(AP312;312:312)(AP313;313:313)(AP314;314:314)(AP315;315:315)(AP316;316:316)(AP317;317:317)(AP318;318:318)(AP319;319:319)(AP320;320:320)(AP321;321:321)(AP322;322:322)(AP323;323:323)(AP324;324:324)(AP325;325:325)(AP326;326:326)(AP327;327:327)(AP328;328:328)(AP329;329:329)(AP330;330:330)(AP331;331:331)(AP332;332:332)(AP333;333:333)(AP334;334:334)(AP335;335:335)(AP336;336:336)(AP337;337:337)(AP338;338:338)(AP339;339:339)(AP340;340:340)(AP341;341:341)(AP342;342:342)(AP343;343:343)(AP344;344:344)(AP345;345:345)(AP346;346:346)(AP347;347:347)(AP348;348:348)(AP349;349:349)(AP350;350:350)(AP351;351:351)(AP352;352:352)(AP353;353:353)(AP354;354:354)(AP355;355:355)(AP356;356:356)(AP357;357:357)(AP358;358:358)(AP359;359:359)(AP360;360:360)(AP361;361:361)(AP362;362:362)(AP363;363:363)(AP364;364:364)(AP365;365:365)(AP366;366:366)(AP367;367:367)(AP368;368:368)(AP369;369:369)(AP370;370:370)(AP371;371:371)(AP372;372:372)(AP373;373:373)(AP374;374:374)(AP375;375:375)(AP376;376:376)(AP377;377:377)(AP378;378:378)(AP379;379:379)(AP380;380:380)(AP381;381:381)(AP382;382:382)(AP383;383:383)(SY0;768:768)
```

The channel map describes the order of graphs in SpikeGLX displays. The
header for the imec stream, here (384,384,1) indicates there are:

* 384 AP-band channels,
* 384 LF-band channels,
* 1 SY (sync) channel.

Each subsequent entry in the map has two fields, (:)-separated:

* Channel name, e.g., 'AP2;2'
* Zero-based order index.

>Note: There are map entries only for saved channels.


_fin_

