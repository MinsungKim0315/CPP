//////Hangman Game(String class)
//////1. 제시 단어 랜덤 선택 
//////2. 글자 수만큼 밑줄(_) 표시
//////3. 알파벳 26개 중 1개 입력 받기
//////4. 알파벳이 있을 경우 알파벳 표시, 없을 경우 기회(life) 1개 소모.
//////5. 게임 진행하는 동안 찾기 실패한 알파벳 목록 표시
//////   중복된 입력의 경우 예외처리, 재입력
//////6. 총 기회(life) 10번
#include <iostream>
#include <string>
using namespace std;
enum menu { Play = 1, Terminate, Cheat };
string word[] = { "inform", "advise", "service", "provide", "relationship", "behave", "improve", "individual", "require", "million",
        "social", "amount", "employ", "terrible", "attitude", "research", "audience", "volunteer", "influence", "international",
        "opportunity", "ability", "expense", "involve", "stress", "therefore", "average", "ride", "local", "encourage", "determine",
        "comfort", "consume", "object", "impress", "available", "contain", "diet", "recognize", "material", "positive",	"emotion",
        "amaze", "level", "mine", "essence", "benefit", "affect", "reduce", "chemistry", "immediate", "thus", "proper",	"profession",
        "economic", "cell", "focus", "issue", "poetry", "demand", "occur", "complex", "define", "proud", "aware", "contact", "performance",
        "detail", "approach", "participate", "fashion", "package", "disappear", "career", "secure", "novel", "despite", "background", "solution",
        "generate", "eventually", "decrease", "recycle", "desire", "balance", "publish", "congratulate", "compose", "digital", "negative", "occasion",
        "replace", "expert", "term", "relieve", "describe", "biology", "due", "equipment", "account", "birth", "constant", "genius", "reflect", "illness",
        "frequent", "steady", "extreme", "tend", "insist", "extend", "politics", "lonely", "habitat", "mental", "factor", "exchange", "active", "species",
        "athletic", "dental", "delight", "confident", "gradual", "electricity", "shadow", "access", "announce", "tense", "firm", "vary", "injure", "permit",
        "threat", "flood", "disabled", "lack", "signify", "concentrate", "emphasize", "astronomy", "commerce", "capable", "fuel", "manufacture", "movement",
        "combine", "gene", "response", "victim", "pressure", "accompany", "frustrate", "construct", "fiction", "laughter", "entertain", "predict", "apologize",
        "outdoor", "sight", "quantity", "conclude", "donate", "personality", "struggle", "electronic", "absorb", "advantage", "incredible", "enable", "instruction",
        "assume", "attempt", "variety", "confuse", "indicate", "analyze", "labor", "remark", "moral", "embarrass", "claim", "stock", "resident", "reasonable",
        "interrupt", "discount", "creature", "heal", "stranger", "revolution", "criticize", "convince", "feature", "tide", "establish", "obtain", "assist",
        "disaster", "efficient", "terrific", "react", "independent", "theory", "qualify", "clue", "recall", "risk", "cancer", "treatment", "specific", "engage",
        "motivate", "import", "elder", "depress", "fascinate", "violent", "alarm", "edge", "deserve", "route", "psychology", "mole", "passion", "weed", "conscience",
        "stripe", "salary", "pose", "purchase", "length", "occupy", "acquire", "interact", "grocer", "lifetime", "decade", "grain", "meaningful", "brief",
        "severe", "survival", "comment", "leap", "survey", "mechanic", "mood", "mere", "typical", "approve", "rural", "finance", "operation", "crime", "awful",
        "series", "exhausted", "flu", "surround", "display", "policy", "mass", "committee", "accurate", "arrange", "consult", "reward", "recover", "facility",
        "dust", "downtown", "attach", "monster", "enormous", "domestic", "elementary", "refer", "gap", "Renaissance", "journey", "plain", "previous", "slight",
        "leisure", "telescope", "stroke", "delicious", "breed", "muscle", "delay", "file", "ethic", "instant", "reveal", "junk", "urban", "witness", "admit",
        "device", "owe", "intend", "award", "preserve", "underground", "consequence", "aspect", "target", "headache", "horizon", "accomplish", "surf", "adopt",
        "potential", "slip", "civilization", "row", "atmosphere", "label", "decorate", "identify", "secretary", "scale", "addict", "evident", "seldom", "standard",
        "basis", "automatic", "region", "sake", "artificial", "possess", "substance", "realistic", "physics", "encounter", "differ", "principle", "memorize",
        "evaluate", "fulfill", "staff", "tremendous", "application", "vote", "railroad", "cooperate", "emit", "request", "guarantee", "resist", "grant", "permanent",
        "emergency", "rid", "impact", "theme", "rely", "hesitate", "location", "organism", "resolve", "curve", "suitable", "distribute", "restrict", "rainforest",
        "circumstance", "interpret", "recite", "annoy", "fright", "estimate", "cabin", "adventure", "entrance", "persuade", "gear", "ray", "release", "slave",
        "perceive", "rank", "nowadays", "symphony", "envy", "corporate", "autograph", "retire", "appeal", "identical", "innocence", "investment", "authority",
        "alternative", "infant", "calculate", "charity", "guilt", "whereas", "broad", "ignorant", "mummy", "pure", "extinct", "household", "chapter", "refund",
        "institute", "lately", "luxury", "ashamed", "dense", "rescue", "mount", "destination", "expand", "evolution", "isolate", "gravity", "genuine", "status",
        "compete", "military", "logic", "commit", "sensible", "sum", "conserve", "swing", "reproduce", "tone", "concept", "invitation", "precise", "formal",
        "particle", "cancel", "departure", "apparent", "visual", "agriculture", "rite", "poverty", "sculpture", "descend", "leak", "portion", "companion",
        "diligent", "distinct", "component", "shave", "universal", "trap", "eager", "legal", "demonstrate", "democracy", "mature", "brilliant", "annual", "faith",
        "spare", "transfer", "refrigerator", "oppose", "desperate", "remote", "offend", "awake", "spaceship", "insight", "trousers", "civil", "complicated",
        "backpack", "tropics", "minor", "duty", "pause", "option", "digest", "shortage", "laboratory", "generous", "laundry", "transform", "discipline",
        "kindergarten", "forbid", "ultimate", "thrive", "royal", "ruin", "manual", "evil", "horror", "worship", "afterward", "client", "insure", "scarce", "fancy",
        "surgery", "assign", "regulate", "shelf", "highway", "utility", "yield", "decline", "aside", "tolerate", "cottage", "coincidence", "contemporary", "bless",
        "prey", "prior", "necessity", "abstract", "league", "fuse", "confirm", "explain", "imitate", "defeat", "niece", "illustrate", "pupil", "intellect", "spice",
        "tempt", "inspire", "dine", "literal", "resort", "grab", "alien", "alcohol", "wreck", "triumph", "document", "suspect", "propose", "install", "prohibit",
        "appropriate", "scholarship", "execute", "trunk", "receipt", "defect", "commute", "trait", "split", "modest", "virtual", "nutrition", "inner", "contrary",
        "ensure", "supervise", "inhabit", "earthquake", "enroll", "seal", "greed", "debate", "spray", "abandon", "conquer", "nevertheless", "volcano", "contract",
        "retail", "prejudice", "agency", "nurture", "priest", "elegant", "lawn", "impose", "masterpiece", "harsh", "drought", "arise", "criteria", "extraordinary",
        "swallow", "dim", "general", "scream", "ladder", "spill", "glare", "modify", "usual", "routine", "eliminate", "deny", "sensitive", "tragic", "deprive",
        "interfere", "temporary", "council", "adolescent", "arctic", "capture", "mill", "associate", "warehouse", "crew", "barrier", "pedestrian", "welfare",
        "cliff", "irritate", "glance", "cruel", "fold", "trial", "tribe", "profound", "annals", "distinguish", "statement", "prevail", "infection", "widespread",
        "drastic", "fade", "needle", "weapon", "reinforcement", "germ", "endanger", "pile", "atom", "peer", "enrich", "galaxy", "renew", "adjust", "noble",
        "candidate", "ideal", "statistics", "ethnic", "foretell", "wonder", "wholesale", "debt", "representative", "oral", "realize", "excess", "appliance",
        "furthermore", "command", "ecosystem", "nap", "fame", "shift", "outstanding", "drift", "mislead", "dedicate", "eyesight", "initial", "beard", "haste",
        "crush", "confront", "destiny", "hardship", "valid", "idiom", "dispose", "fiber", "hydrogen", "thread", "dynasty", "scatter", "gamble", "temper", "craft",
        "undoubtedly", "raft", "rubber", "soak", "specialist", "combat", "cease", "ceiling", "unify", "perspective", "doom", "bump", "genre", "erase", "moderate",
        "graze", "vital", "incident", "session", "fragile", "review", "geometry", "budget", "suffix", "fur", "indifferent", "strain", "wrinkle", "ingredient",
        "dismiss", "glacier", "urge", "celebrity", "antique", "sphere", "inherit", "disgrace", "crawl", "scratch", "diabetes", "congestion", "constitute", "barter",
        "investigate", "circular", "chilly", "activate", "fierce", "vague", "editorial", "magnet", "chatter", "obstacle", "fertile", "abolish", "assure", "rehearse",
        "gender", "innovation", "emperor", "dwell", "opponent", "chore", "fossil", "glitter", "carve", "decay", "protein", "backward", "tissue", "refresh", "miniature",
        "acne", "lord", "substitute", "scan", "pottery", "layer", "scent", "radiant", "exclaim", "polish", "flavor", "imprint", "heritage", "strive", "property",
        "majesty", "portray", "subscribe", "shrug", "wage", "asset", "intimate", "merit", "launch", "conference", "reception", "administer", "vicious", "cherish",
        "accuse", "eternal", "robber", "overwhelm", "transmit", "copper", "orbit", "smash", "discard", "famine", "pill", "enhance", "immune", "superior", "string",
        "cope", "raw", "moist", "cattle", "loan", "obedient", "procedure", "bond", "therapy", "subtle", "depict", "radical", "angle", "caution", "persist", "reverse",
        "architecture", "territory", "strategy", "hence", "panic", "wilderness", "necklace", "category", "murder", "funeral", "clip", "flush", "omit", "outcome",
        "alert", "despair", "compact", "embassy", "astonish", "optimistic", "loyal", "humid", "rumor", "deluxe", "delicate", "inflate", "adequate", "physician",
        "joint", "via", "passage", "cradle", "vessel", "restore", "passive", "idiot", "marble", "classify", "fundamental", "transaction", "sufficient", "stable",
        "sympathy", "eyebrow", "edible", "federal", "bud", "trivial", "anxiety", "tablet", "dizzy", "liquid", "contend", "outlook", "roam", "decent", "tenant" };
class hangman {
private:
    int wordsCnt; // 단어 목록 총 수량
    string answer; // 게임 진행 답안
    string hideAnswer; // 게임 진행 숨긴 답안
    string bad; // 실패 기록 답안 목록
    int Life; // 총 기회 10번
public:
    void init() {   //멤버 변수 초기화
        answer = word[rand() % _countof(word)]; //_countof: 배열 내 요소 개수 구하는 메크로
        string temp(answer.length(), '_');  //'_'를 answer.length() 만큼 생성하여 temp라는 배열에 삽입
        hideAnswer = temp;
        Life = 10;
        bad.clear();    //문자열 삭제
    }
    int lifeCheck() { return Life; } // life 값 확인
    void printAnswer(int n = 0) { // 답안 진행 상태 출력
        cout << "실패한 알파벳: " << bad << endl;
        cout << Life << "번 기회가 남았습니다.\n\n";
        if (n == 3)cout << answer << endl;
        cout << hideAnswer << endl;
    }
    void menu(int& menu) { // 게임 메뉴판 출력
        cout << " [ Hangman Game !! ] \n";
        cout << " 1. Play \n";
        cout << " 2. Exit \n";
        cout << " 3. Cheat\n";
        cout << " 메뉴를 입력하세요. : ";
        do {
            while (!(cin >> menu)) {
                cin.clear();
                while (cin.get() != '\n');
                cout << " 메뉴를 입력하세요. : ";
            }
            while (cin.get() != '\n');
        } while (menu <= 0 || 4 <= menu);

    }
    bool isSolve() { // 정답 확인 함수
        return answer == hideAnswer;
    }
    bool guesses(char letter) {// 입력받은 알파벳 & 답안 비교
        if (bad.find(letter) != string::npos || hideAnswer.find(letter) != string::npos) {  //존재여부 확인
            cout << "\t\t[이미 시도한 알파벳 입니다.]\n\n";
            return false;
        }
        for (int i = 0; i < answer.size(); i++) {
            if (answer[i] == letter) hideAnswer[i] = letter;
        }
        if (hideAnswer.find(letter) == -1) {
            bad += letter;
            Life--;
            return false;
        }
        return true;
    }
};
int main() {
    srand(time(0));
    hangman game;
    int menu = 0;
    for (;; system("pause")) {
        system("cls");
        game.menu(menu);
        switch (menu) {
        case Cheat: //switch문에서 해당 case에 아무것도 없으면 break문 나올 때까지 전체 실행
        case Play:
            game.init();
            while (!game.isSolve() && game.lifeCheck() > 0) {
                game.printAnswer(menu);
                char letter;
                cin >> letter;
                while (cin.get() != '\n');
                game.guesses(letter);
            }
            game.printAnswer(3); //Cheat인 경우
            if (game.isSolve()) cout << " \t\t ★☆★☆축하합니다. 정답을 맞추셨습니다.!!☆★☆★ \n\n";
            else cout << "\t\tㅠ.ㅠ 정답을 맞추지 못 했습니다.\n\n";
            break;
        case Terminate:
            cout << "\n [ 프로그램 종료 합니다. ] \n";
            exit(0);
        }
    }
    return 0;
}
