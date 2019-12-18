//===============================================================================
// Copyright 2019 NVISO sA
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//===============================================================================

#include <cstdlib>
#include <stdio.h>
#include "float.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>

#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

template <std::ctype_base::mask mask>
class IsNot
{
    std::locale myLocale;       // To ensure lifetime of facet...
    std::ctype<char> const* myCType;
public:
    IsNot( std::locale const& l = std::locale() )
        : myLocale( l )
        , myCType( &std::use_facet<std::ctype<char> >( l ) )
    {
    }
    bool operator()( char ch ) const
    {
        return ! myCType->is( mask, ch );
    }
};

typedef IsNot<std::ctype_base::space> IsNotSpace;

std::string trim( std::string const& original )
{
    std::string::const_iterator right = std::find_if( original.rbegin(), original.rend(), IsNotSpace() ).base();
    std::string::const_iterator left = std::find_if(original.begin(), right, IsNotSpace() );
    return std::string( left, right );
}

struct pred {
	int index;
	float conf;
};

struct greater_than_key
{
	inline bool operator() (const pred& struct1, const pred& struct2)
	{
		return (struct1.conf > struct2.conf);
	}
};


void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch);
 
	// Repeat till end is reached
	while( pos != std::string::npos)
	{
		// Replace this occurrence of Sub String
		data.replace(pos, toSearch.size(), replaceStr);
		// Get the next occurrence from the current position
		pos =data.find(toSearch, pos + replaceStr.size());
	}
}

int main(int argc, char* argv[])
{
	if (argc != 4) {
		return -1;
	}

	std::string imagenet_dump_file = argv[1];
	std::string ground_truth_labels_file = argv[2];	
	std::string classes_file = argv[3];

    // read classes
    std::vector<std::string> classes;
    std::ifstream ifs(classes_file.c_str());
    if (!ifs.is_open()) {
        cout << "File " << classes_file << " not found" << endl;
        return -1;
    }
    std::string line;
    while (std::getline(ifs, line)) {
        classes.push_back(line);
    }

    // read classes
    std::vector<std::string> ground_truth_labels;
    std::ifstream ifs2(ground_truth_labels_file.c_str());
    if (!ifs2.is_open()) {
        cout << "File " << ground_truth_labels_file << " not found" << endl;
        return -1;
    }
    while (std::getline(ifs2, line)) {
        ground_truth_labels.push_back(line);
    }

    // read predictions 
    ifstream infile(imagenet_dump_file.c_str());   

    int total_count = 0;
    float top1_acc = 0.f;
    float top5_acc = 0.f;

    while(getline(infile, line)) 
    {
        stringstream linestream(line);
        vector<string> values;
        string v;        
        while(getline(linestream, v, ':')) {
            values.push_back(trim(v));
        }
        if(values.size() != 2) 
            break;
        
        cout << "Image: " << values[0] << endl;

        findAndReplaceAll(values[0], "ILSVRC2012_val_", "");
        int image_id = std::stoi(values[0]);
        
        stringstream linestream2(values[1]);
        std::vector<pred> m_pred;
        int index = 0;
        while(getline(linestream2, v, ' ')) {
            pred p;
            p.index = index;
            p.conf = std::stof(v);
            m_pred.push_back(p);
            index++;
        }

        if(m_pred.size() != 1000) {
            cout << "Data Error: " << values[0].c_str() << " Image predictions " << m_pred.size() << endl;
            return -1;
        }
	    std::sort(m_pred.begin(), m_pred.end(), greater_than_key());
        
        cout << "Top Pred: " << classes[m_pred[0].index] << ", " << m_pred[0].conf << endl;
        cout << "GT: " << ground_truth_labels[image_id] << endl;
        if(ground_truth_labels[image_id] == classes[m_pred[0].index])
            top1_acc++;

        for(int i=0; i<5; i++) 
        {
            if(ground_truth_labels[image_id] == classes[m_pred[i].index])
                top5_acc++;
        }

        total_count++;
        break;
    }

    cout << "Top 1 Accuracy: " << top1_acc/total_count * 100 << "'%'" << endl;
    cout << "Top 5 Accuracy: " << top5_acc/total_count * 100 << "'%'" << endl;
}