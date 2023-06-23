// 2023/05/18 22:01:29
#include <bits/stdc++.h>
using namespace std;

vector<vector<__int128_t>> mul(const vector<vector<__int128_t>>& a, const vector<vector<__int128_t>>& b)
{
    vector<vector<__int128_t>> c(a.size(), vector<__int128_t>(a[0].size(), 0));
    for (size_t i = 0; i < a.size(); i++)
        for (size_t j = 0; j < b[0].size(); j++)
            for (size_t k = 0; k < b.size(); k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
    
    return c;
}

vector<vector<__int128_t>> pow(vector<vector<__int128_t>> a, __int128_t n)
{
    vector<vector<__int128_t>> b(a.size(), vector<__int128_t>(a[0].size(), 0));
    for (size_t i = 0; i < a.size(); i++)
        b[i][i] = 1;
    while (n)
    {
        if (n & 1)
            b = mul(a, b);
        a = mul(a, a);
        n /= 2;
    }
    return b;
}

__int128_t fib(__int128_t n)
{
    if (n <= 2)
        return 1;
    else
    {
        return pow({ {1, 1}, {1, 0} }, n)[1][0];
    }
}

void print_int128(__int128_t n)
{
    if (n / 10)
        print_int128(n / 10);
    cout.put((char)(n % 10 + '0'));
}

ostream& operator << (ostream& out, __int128_t n)
{
    print_int128(n);
    return out;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // for (int i = 0; i < 1000; i++)
    //     cout << fib(i) << ' ';

    string str = "1077773489307297478027903885511948082962510676941157978490230921003274473536465230498488444020476029849319433283274054953307539817330483067414835387175554540519844620087346424938072325821301670190811988251618614959586085409937375106530448744637829968513893256636681633131732045918931898863135599612655615546389764030557151405397922601243227304829000716908863786206755177008322693280878498662740588365375937582745087047441929768088349613112971288592851767548484151032523851465334921528252459084466698411101587182887301894506311341515623798245893600417568995720126596157628990959355731402138029685765390557089535847112683962321195360189733388114238140515264593740927152326504059583750815213732368481593236728447575119467557464554422126542220275696283937536759059155955463878564256896667116761467384803801434909803321471265525245144152549832048734930166056768820668771759919744444935935088639508014800544331468556549936334994139143072089673319542213769664519855004306020366507003052291723041808934238051920953410007158729893603386457670243188709645798965413747164667906577936267866196457775757252015252068493715000460956718593142123341990626215459893933077132059613701637301087675999606255687706667591676091409577877451663668287538782197418996327734228301092476982626873928576490563480059410310767526696258416645787778507414220704441130914493668425195910176918761448464396869983540535428776253464879551756244862159817408126456774225752803753838399845933757396201602416068842272523487140676462153030586204625113611434042433798760578652117922768659247166354431987943463843003939890821453509262965233902059369238673525294206131750551625882357774114071358826125773212222415075574803998022214274948740799210572359084607321757510709230245040535821780299001683552089622478492821696389953101404432463976483368103166182454835144828572325165031466503598458267317211993173365145809936143008326989566407562507349640887192313422925890193544883744743179727153441102714065881520580800020703833148947768887649191217797780979925592987356964202390623983465277804263308821933051679883889295266504139825370287752631917589681462250484938100037614775188338234832218620895846937534869553149128721601417705627313643081288948613138219163025293502371819159964259808237634023944931332062605474612272279529426331164678088155095646499466245557649737684860053738504901734266039739248324716625233531964886694788142734276445419008184313311285634528998213366980652066093433365043971592724637670468056377718948001726470920269147563047690456061135449238592015854761083538522702832146058168406399364954040520312306429657043970818858218160287319473973542885349326873880702527039319014025425047674928003622157175606361221575771548307134889801648417805407682784567024531556241603011884695211901247893641848955660423954234060275086391900543714565307315974261376130677387011843248554909313482884510304468810023601212358542690835193336851063797643620778280627109031980839538821279264429549745862240679506906449939373868213045019493727878607758972681525013807476516567635263938687279182306523896293479421812775275767067080834661210060051449791193755194190272728264690837515587718472613394334005550731610759189196968295860856861127020272643374476594416348575355559350638645878075115101672843266839395295381516632463411691476527413885271733639979859771479701207382441862353688808431127070705443538393969991680729860997643787330361260452079179396215604783758857968160780376962005355105386101336700557030472593829600047682758904638946037995486421545466364591300907318692931557088089086195527051967319521656496879035621255086701042537404765688643583452932585495452656385578238942025984173701721726864251831594213215214887668013508259781248399946219087345016625368706423157916003496183228244221682588630755402774473006338257125053879794762007437829800385369171749592778397346486327639016218711371892595610580707152762581359953265897623888561431188784043844473052571055419223538596910537360352163873550560403153352499121085534012095978028039950967075483974230215432887173636247566623653380866864430165175366352610819322424161233092164312788407197728087032050242455296087274026149289728159928263937106027206247439203247705490211932980442487754584865236725036261503900272923999666373202619794081335574553272262224605020899992558374066410962363234619005279301784791564988962718852591579853514055187317372760225259278385032595533811723576068841003022532869389869512546991201860699250824699401152332702346215697937912339958175599061438259957388503897441647234171231389242764766139658847848865015454296064721728576055594663714912731505480325845556539532978711005142326842122418012383510399669199064364345355046580787890301614832970226041029108284021409508226100740261823493634691446617576464290209169492370331450663677309353028251465593040128357177052250027208271570162475958870983023951038237863317452827462837487831054529685241949550949300270558322882077594617493238778913673986212126487826512788140241476393543650959905044617726398073232737256400441289404756875082095025276877147072002068920905854395547491023074689952655988273754666079554722185768678339179917272311420903110261709672972820429876481918498528587138377701559889210214565715979078971055224258831946819028198708349528931795666673647713585326447378802655871624873692001133245996495979512491665017864224497401050660184945903924035680374218146194711367607013135028960782279158072703882459958944714887511134589371887360227661908272318939690112306974896858833174918479997120488507247345883095561156569291160773363311668417546453646881624620857813573180522067467140711482126062130699939856646824418267252979262452163383734411769930020367599600041783070096647169520710430984530779404242067445367313738799553275024603565157944491051109070665601404439941303780651854209730366323236086243808427807836753957463728590904062733874450560833790907346524980178737076670939139552105977373544906691655391102374992643002914560871898633256709874214502604984198816587332526831300605181816940481120587769275403445248982637481916391408520977719026098018526264301068727580050276809651792651716778187417438257153462699124447249565395132157534098418741235952746319802948605805611456205430193033596579324052274700134754987235581438252140425609628387606110527624718665488453716388222064628242046530124386099066517029486976032231174356597287928422723062460288788493358147105141511843672692519703933079389596250940749519518888098925655135988885701034055608754787209109532669487862345542862395362198334738551193514126583403099071806642221309860067721397686439793997791874899911592790375937100959177170168572551490609213096576987939444911316491133789751810580383022983881022008306091954322409601718365129974393104526918765567278705004743109508234037000236203693788853661375250567622973987365096071922663911213575659407494821583275920055441280699337966774677324078043916349598025118249971177882181830949863376164307813396603520247309182901757641796189701867666644657221232253811686116690912512665593122088467395732882460984227300618730614550665517158822709423183997675859237499300033514984853418833576097219524912054242267258271598490050901153972060253506226574678670622729692574998296809862577467225312694377023108363334414094355190989667655694415467173655735043735739278776509098374178270845535406317005069492078576483478289010993186205307737966664476771098958901153875491182698550325000552001309512085432894883248703104282593044230754234390695272647660220467324355983500460072684315358072710121127285384136760785378783103917958411954976413486928821058759532423899190358084225493001627000353033052088483748334929693388376318136230371670203359196670944887036147063035829298900896143631330096190057914242480691051968711036751346386916513104107408004257705076970455910557858723075595606915444904699652059156003908374517740263850194645488889167688358164311770641761788556479637620858284349112486366297000113369668619480190214121828164968171572735937095527707418079389610746472056852556923698683510801663730896494924358254425350706886201337834869795550747097370804271993324466140488861182220129154162318726927688938969292645509104916790039580176352365955058324426342204300126312549030595760622495862412634991057720122696284840731881205354830446943593964754164663587362164408781943949394826941923066545013268227299230790816701834137738671563394257084274107548430461739011142089895926922025607576486756312206236476000320258221498865747307869066088007593172717058800631067076025694246089138274686567385092261362361877821865883357996812329393028588861531195675558638677535574037205134653019181464741394364508632886321237869144759613705372635240130896237178985645318435761293363137895788100128813998911451017309988278367279140056990486891770644253869480711351967297092824202984812408878880431609348366135722327305774300128365219671994124950218534758476010543101647183465233462602174992570730116613189011695837136196346010376401485952494303531545751807381703538672148888672857626796472162417153381846603529369168061215869106968133569298701863093974377188004962852429839846398786383902904879497682857610688826661622717722626622250277735138061743992139859564690782235927994815436279154422537138563151659778253356822105524886400502765781650721804764164746233916221399341296264918214925606204501374304277857342560329690471180900430114207491819855872579225525208705654669240631463536275526404830226589992544397711562448807298277242831199965076119043609478712852663234822882865193256113124732013775586212528756087102479608712043180116458627079198279777781613711291295095243391731346239583285733632659648015650286988515006468909920659847545510172427616176240651739916939504597982496521591256133212646747851195837416643424292979101420604760095492319857449030727672157337435668631115590379450566286530080575780763060803482800642069793519164220974968065427952408907932659908102378715272523242170091136614684124158724497988910317528686643460105357181934446922109445999414768301104269876906038785417562116181321330670808593206053807020698071823063330468615629232705045196419148031059705628013608175009331914291885808751962605458474604194206257224753676742372629234677631054260685497191783786688197868052125761772640409495112155761882698223668381539682186867629262907557205675103732451647568429444236992124912404874642815806867508067244510645124441922343362518137645828033764612095719936197364556462149210633588703081823042665930493669537680372203970374907819690111266524020297618305364252373553125";
    cout << str.size();

    cout << flush;
    system("pause");
    return 0;
}