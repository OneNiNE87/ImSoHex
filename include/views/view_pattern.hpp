#pragma once

#include <hex/views/view.hpp>
#include <hex/lang/evaluator.hpp>
#include <hex/lang/pattern_language.hpp>

#include <hex/providers/provider.hpp>

#include <cstring>
#include <filesystem>
#include <string_view>
#include <thread>
#include <vector>

#include <ImGuiFileBrowser.h>
#include <TextEditor.h>

namespace hex {

    class ViewPattern : public View {
    public:
        explicit ViewPattern(std::vector<lang::PatternData*> &patternData);
        ~ViewPattern() override;

        void drawMenu() override;
        void drawAlwaysVisible() override;
        void drawContent() override;

    private:
        lang::PatternLanguage *m_patternLanguageRuntime;
        std::vector<lang::PatternData*> &m_patternData;
        std::vector<std::string> m_possiblePatternFiles;
        int m_selectedPatternFile = 0;
        bool m_runAutomatically = false;
        bool m_compilerRunning = false;

        TextEditor m_textEditor;
        std::vector<std::pair<lang::LogConsole::Level, std::string>> m_console;

        void loadPatternFile(std::string_view path);
        void clearPatternData();
        void parsePattern(char *buffer);
    };

}