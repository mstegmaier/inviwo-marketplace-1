/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2021 Inviwo Foundation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************************/
#pragma once

#include <inviwo/marketplace/marketplacemoduledefine.h>
#include <inviwo/marketplace/downloadmanager.h>
#include <inviwo/core/common/inviwoapplication.h>

#include <string>
#include <optional>
#include <vector>
#include <filesystem>
#include <unordered_map>

namespace inviwo {


struct ModuleSrcData {
    std::string url;
    std::string name;
    std::optional<std::filesystem::path> path;
};

// This is a duplicate, but they may be different at some point...
struct ModuleBinData {
    std::string url;
    std::string name;
    std::optional<std::filesystem::path> path;
};

/**
 * \brief Handles Marketplace Modules
 * Provides functions to update available modules, downloading, building and loading
 */
class IVW_MODULE_MARKETPLACE_API MarketManager {
public:
    MarketManager(InviwoApplication*);
    virtual ~MarketManager() = default;

    std::optional<std::string> gitClone(const std::string&, const std::string&);
    std::optional<std::filesystem::path> getMarketDir() const;

    // Source Market
    void updateModuleSrcData();
    int cloneModule(const ModuleSrcData&);
    int updateModule(const ModuleSrcData&);
    int cmakeConfigure(const ModuleSrcData&);
    const std::vector<ModuleSrcData> getSrcModules() const;

    // Binary Market
    void updateModuleBinData();
    int downloadBinaryModule(const ModuleBinData&);
    void tryLoadModule(const ModuleBinData&);
    const std::vector<ModuleBinData> getBinModules() const;

private:
    InviwoApplication* app_;
    DownloadManager dlManager_;
    std::filesystem::path inviwoSourcePath_;
    std::string repositoryUrl_;
    std::vector<ModuleSrcData> srcModules_;
    std::vector<ModuleBinData> binModules_;
};

}  // namespace inviwo
